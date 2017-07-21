#define _CRT_SECURE_NO_WARNINGS 1
#include "pcap.h"   
#include<winsock2.h>   

#pragma comment(lib,"wpcap.lib")   
#pragma comment(lib,"packet.lib")   
#pragma comment(lib,"ws2_32.lib")   

/*��������̫��Э���ʽ*/
struct ether_header
{
	u_int8_t ether_dhost[6]; //Ŀ��Mac��ַ   
	u_int8_t ether_shost[6]; //ԴMac��ַ   
	u_int16_t ether_type;    //Э������   
};

struct ip_header
{
#if defined(WORDS_BIENDIAN)   
	u_int8_t   ip_version : 4,
ip_header_length : 4;
#else   
	u_int8_t   ip_header_length : 4,
ip_version : 4;
#endif   
	u_int8_t    ip_tos;
	u_int16_t   ip_length;
	u_int16_t   ip_id;
	u_int16_t   ip_off;
	u_int8_t    ip_ttl;
	u_int8_t    ip_protocol;
	u_int16_t   ip_checksum;
	struct in_addr ip_souce_address;
	struct in_addr ip_destination_address;
};

void ip_protool_packet_callback(u_char *argument, const struct pcap_pkthdr* packet_header, const u_char* packet_content)
{
	struct ip_header *ip_protocol;
	u_int header_length;
	u_int offset;
	u_char tos;
	u_int16_t checksum;
	//MAC�ײ���14λ�ģ�����14λ�õ�IPЭ���ײ�   
	ip_protocol = (struct ip_header *) (packet_content + 14);
	checksum = ntohs(ip_protocol->ip_checksum);
	tos = ip_protocol->ip_tos;
	offset = ntohs(ip_protocol->ip_off);
	printf("---------IPЭ��---------\n");
	printf("�汾��:%d\n", ip_protocol->ip_version);
	printf("�ײ�����:%d\n", header_length);
	printf("��������:%d\n", tos);
	printf("�ܳ���:%d\n", ntohs(ip_protocol->ip_length));
	printf("��ʶ:%d\n", ntohs(ip_protocol->ip_id));
	printf("ƫ��:%d\n", (offset & 0x1fff) * 8);
	printf("����ʱ��:%d\n", ip_protocol->ip_ttl);
	printf("Э������:%d\n", ip_protocol->ip_protocol);
	switch (ip_protocol->ip_protocol)
	{
	case 1: printf("�ϲ�Э����ICMPЭ��\n"); break;
	case 2: printf("�ϲ�Э����IGMPЭ��\n"); break;
	case 6: printf("�ϲ�Э����TCPЭ��\n"); break;
	case 17: printf("�ϲ�Э����UDPЭ��\n"); break;
	default:break;
	}
	printf("�����:%d\n", checksum);
	printf("ԴIP��ַ:%s\n", inet_ntoa(ip_protocol->ip_souce_address));
	printf("Ŀ�ĵ�ַ:%s\n", inet_ntoa(ip_protocol->ip_destination_address));
}

void ethernet_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr* packet_header, const u_char* packet_content)
{
	u_short ethernet_type;
	struct ether_header *ethernet_protocol;
	u_char *mac_string;
	static int packet_number = 1;
	printf("----------------------------------------------\n");
	printf("�����%d���������ݰ�\n", packet_number);
	printf("����ʱ��:\n");
	printf("%s", ctime((const time_t*)&packet_header->ts.tv_sec));
	printf("���ݰ�����:\n");
	printf("%d\n", packet_header->len);
	printf("---------��̫��Э��---------\n");
	ethernet_protocol = (struct ether_header*)packet_content;//������ݰ�����   
	printf("��̫������:\n");
	ethernet_type = ntohs(ethernet_protocol->ether_type);//�����̫������   
	printf("%04x\n", ethernet_type);
	switch (ethernet_type)
	{
	case 0x0800: printf("�ϲ�Э����IPЭ��\n"); break;
	case 0x0806: printf("�ϲ�Э����ARPЭ��\n"); break;
	case 0x8035: printf("�ϲ�Э����RARPЭ��\n"); break;
	default:break;
	}
	printf("MAC֡Դ��ַ:\n");
	mac_string = ethernet_protocol->ether_shost;
	printf("%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));
	printf("MAC֡Ŀ�ĵ�ַ:\n");
	mac_string = ethernet_protocol->ether_dhost;
	printf("%02x:%02x:%02x:%02x:%02x:%02x\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));
	if (ethernet_type == 0x0800)//��������IPЭ��   
	{
		ip_protool_packet_callback(argument, packet_header, packet_content);
	}
	printf("----------------------------------------------\n");
	packet_number++;
}

int main()
{
	pcap_t* pcap_handle; //winpcap���   
	char error_content[PCAP_ERRBUF_SIZE]; //�洢������Ϣ   
	bpf_u_int32 net_mask; //�����ַ   
	bpf_u_int32 net_ip;  //�����ַ   
	char *net_interface;  //����ӿ�   
	struct bpf_program bpf_filter;  //BPF���˹���   
	char bpf_filter_string[] = "ip"; //���˹����ַ�����ֻ����IPv4�����ݰ�   
	net_interface = pcap_lookupdev(error_content); //�������ӿ�   
	pcap_lookupnet(net_interface, &net_ip, &net_mask, error_content); //��������ַ�������ַ   
	pcap_handle = pcap_open_live(net_interface, BUFSIZ, 1, 0, error_content); //������ӿ�   
	pcap_compile(pcap_handle, &bpf_filter, bpf_filter_string, 0, net_ip); //������˹���   
	pcap_setfilter(pcap_handle, &bpf_filter);//���ù��˹���   
	if (pcap_datalink(pcap_handle) != DLT_EN10MB) //DLT_EN10MB��ʾ��̫��   
		return 0;
	pcap_loop(pcap_handle, 10, ethernet_protocol_packet_callback, NULL); //����10�����ݰ����з���   
	pcap_close(pcap_handle);
	return 0;
}
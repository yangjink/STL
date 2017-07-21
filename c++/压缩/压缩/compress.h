#pragma once 



typedef long long LongType;

struct CharInfo
{  
	LongType _count;//字符出现的次数
	string _code;//huffman编码
	unsigned char _ch;//字符
	CharInfo(LongType count = 0)
		:_count(count)
		, _code("")
	{}
	bool operator!=(const CharInfo& info) const
	{
		return _count != info._count;
	}
	CharInfo operator+(const CharInfo& info)
	{
		return CharInfo(_count + info._count);
	}
	/*bool operator<=(const CharInfo& info) const
	{
		return(( _count < info._count) || (_count == info._count));
	}
	bool operator>=(const CharInfo& info) const
	{
		return((_count > info._count) || (_count == info._count));
	}*/
};

struct CountInfo
{
	int _ch;
	LongType _count;
};
class CompressFile
{
public:
	CompressFile()//对其字符进行初始化
	{
		for (size_t i = 0; i <= 256; i++)
		{
			_infos[i]._ch = i;
		}
	}

	void Compress(const char* filename)
	{
		assert(filename);
		FILE* fout = fopen(filename, "rb");
		assert(fout);
		//char ch = fgetc(fout);
		int ch = fgetc(fout);
		while (ch != EOF)
		{
			_infos[(unsigned char)ch]._count++;
			ch = fgetc(fout);
		}
		//fclose(fout);
		CharInfo invalid;
		invalid._count = 0;
		HuffmanTree<CharInfo> tree(_infos, 256,invalid);

		GetHuffmanCode(tree.Root());



		string compressFile = filename;
		compressFile += ".huffman";
		FILE* fin = fopen(compressFile.c_str(), "wb");
		assert(fin);
		
		CountInfo info;
		for (size_t i = 0; i < 256; ++i)
		{
			if (_infos[i]._count)
			{
				info._ch = _infos[i]._ch;
				info._count = _infos[i]._count;
				
				fwrite(&info,sizeof(info),1,fin);
			}
		}
		//CharInfo info1;
		info._count = -1;
		fwrite(&info, sizeof(info), 1, fin);



		fseek(fout,0, SEEK_SET);
		ch = fgetc(fout);
		unsigned char value = 0;
		int pos = 0;
		while (!feof(fout))
		{
			string& code = _infos[ch]._code;
			for (size_t i = 0; i < (code.size()); ++i)
			{
				value <<= 1;
				++pos;
				if (code[i] == '1')
					value |= 1;

				if (pos == 8)
				{
					printf("%d ", value);
					fputc(value, fin);
					value = 0;
					pos = 0;
				}
			}
			//cout << ch << " ";
			ch = fgetc(fout);
		}

		if (pos)
		{
			value <<= (8 - pos);
			fputc(value, fin);
		}
		fclose(fin);
		fclose(fout);
		
	}
	void UnCompress(const char* filename)//当这个文件中只有一种字符时，只有一个根节点
	{
		assert(filename);


		string uncompressFile = filename;
		size_t index = uncompressFile.rfind('.');
		assert(index != string::npos);
		uncompressFile = uncompressFile.substr(0, index);
		index = uncompressFile.rfind('.');
		assert(index != string::npos);
		uncompressFile = uncompressFile.substr(0, index);
		uncompressFile += "1.jpg";
		



		


		FILE* fout = fopen(filename, "rb");
		assert(fout);

		FILE* fin = fopen(uncompressFile.c_str(), "wb");
		assert(fin);

		CountInfo info;
		
		while (1)
		{
			fread(&info, sizeof(CountInfo), 1, fout);
			if (info._count == -1) 
				break;
			_infos[info._ch]._ch = info._ch;
			_infos[info._ch]._count = info._count;
			
		} 
		
		

		CharInfo invalid;
		invalid._count = 0;

		HuffmanTree<CharInfo> tree(_infos, 256, invalid);
		HuffmanTreeNode<CharInfo>* root = tree.Root();
		HuffmanTreeNode<CharInfo>* cur = root;
		LongType count = root->_w._count;

		unsigned char value = fgetc(fout);

		if (root->_left == NULL && root->_right == NULL)
		{
			LongType count1 = count;
			while (count1)
			{
				cout << cur->_w._ch<<" ";
				fputc(cur->_w._ch, fin);
				count1--;
			}
		}
		while (!feof(fout))
		{
			int pos = 7;
			char test = 1;
			while (pos >= 0 )
			{
				if (value &(test << pos))
					cur = cur->_right;
				else
					cur = cur->_left;

				--pos;
				if (cur->_left == NULL && cur->_right == NULL)
				{
					//fflush(stdin);
					
					//cout << cur->_w._ch << " ";
					fputc(cur->_w._ch, fin);
					cur = root;
					count--;
				}
			}
			if (count == 0)
				break;
			value = fgetc(fout);
			
		}
		fclose(fout);
		fclose(fin);

	}
protected:
	void GetHuffmanCode( HuffmanTreeNode<CharInfo>* root)
	{
		if (root == NULL)
			return ;

		if (root->_left == NULL && root->_right == NULL)
		{
			HuffmanTreeNode<CharInfo> *parent, *cur;
			cur = root;
			parent = cur->_parent;
			string& code = _infos[(unsigned)root->_w._ch]._code;
			while (parent)
			{
				if (cur == parent->_left)
					code += '0';
				else
					code += '1';

				cur = parent;
				parent = cur->_parent;
			}
			reverse(code.begin(), code.end());
			return;
			//_infos[root->_w._ch]._code = code;
		}

		GetHuffmanCode(root->_left);
		GetHuffmanCode(root->_right); 
	}

	
protected:
	CharInfo _infos[256];
};


void Test1()
{
	CompressFile c1;
	cout << "压缩中：" << endl;
 	c1.Compress("psb.jpg");
	
	cout << "----------------------------------------------------------------" << endl;
	cout << "解压中" << endl;
	//c1.UnCompress("psb.jpg.huffman");
	
	CompressFile c2;
	c1.UnCompress("psb.jpg.huffman");

}
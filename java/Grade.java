 public class  Grade
{

      public static void main(String[] args)
     { 

         System.out.println(X(100));
      }
       
      public static char X(int x)
        {
           
              int num=0;
              if(x>=85){ num=1;}
              if(x>=70&&x<85){ num=2;}
              if(x>=60&&x<70){ num=3;}
              if(x<=60){ num=4;} 
              switch(num)
                {
                   case 1:
                        return  'A'; 
                   case 2:
                        return  'B';
                   case 3:
                        return  'C'; 
                   case 4:
                        return  'D'; 
                 }
 return 0;
        }

}
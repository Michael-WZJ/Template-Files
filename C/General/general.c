#include "general.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
/*                          Functions from Neil                             */
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

// 在stderr打印 字符串s，结束程序
void on_error(const char* s)
{
   fprintf(stderr, "%s\n", s);
   exit(EXIT_FAILURE);
}

// 分配空间，用法同calloc
void* ncalloc(int n, size_t size)
{
   void* v = calloc(n, size);
   if(v==NULL){
      on_error("Cannot calloc() space");
   }
   return v;
}

// free 整个存了h个指针的数组p
void n2dfree(void**p, int h)
{
   int i;
   for(i=0; i<h; i++){
      free(p[i]);
   }
   free(p);
}


void** n2drecalloc(void** p, int oh, int nh, int ow, int nw, size_t szelem)
{

   void** n;
   int j;
   n = n2dcalloc(nh, nw, szelem);
   for(j=0; j<oh; j++){
      memcpy(n[j], p[j], ow*szelem);
   }
   n2dfree(p, oh);
   return n;

}

// 给存了h个指针的数组p分配空间，其中每个指针指向长度为w的数组，返回p
void** n2dcalloc(int h, int w, size_t szelem)
{

   int i;
   void** p;
   p = calloc(h, sizeof(void*));
   if(p==NULL){
      on_error("Cannot calloc() space");
   }
   for(i=0; i<h; i++){
      p[i] = calloc(w, szelem);
      if(p[i]==NULL){
         on_error("Cannot calloc() space");
      }
   }
   return p;
}

// 把指针p指向的空间内的 oldbytes个字节 复制到 有nwbytes个字节空间的新指针n，再把p free掉， 返回n
void* nrecalloc(void* p, int oldbytes, int newbytes)
{
   void* n = calloc(newbytes, 1);
   if(n==NULL){
      on_error("Cannot calloc() space");
   }
   memcpy(n, p, oldbytes);
   free(p);
   return n;
}

// 重新分配 bytes字节 给 指针p，用法同realloc
void* nremalloc(void* p, int bytes)
{
   void* n = realloc(p, bytes);
   if(n==NULL){
      on_error("Cannot malloc() space");
   }
   return n;
}

// 以mode模式读取文件fname
void* nfopen(char* fname, char* mode)
{
   FILE* fp;
   fp = fopen(fname, mode);
   if(!fp){
      on_error("Cannot open file");
   }
   return fp;
}

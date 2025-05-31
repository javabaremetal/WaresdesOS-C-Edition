void SetPReact(int x, int y, int lar, int alt, 
               unsigned char R1, unsigned char G1, unsigned char B1,
               unsigned char R2, unsigned char G2, unsigned char B2);
               
void SetTPixel(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha);

void SetTPReact(int x, int y, int lar, int alt,
                unsigned char R1, unsigned char G1, unsigned char B1,
                unsigned char R2, unsigned char G2, unsigned char B2,
                unsigned char alpha) ;
                
void SetTReact(int x, int y, int lar, int alt, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha) ;

void printf(char *ff,...);
void putchar(char ff);
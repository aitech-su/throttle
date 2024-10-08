#ifndef __FONT_12864_H
#define __FONT_12864_H 	 
#include "font_table.h"
//����ASCII��
//ƫ����32 
//ASCII�ַ���: !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
//PC2LCD2002ȡģ��ʽ���ã�����+����ʽ+˳��+C51��ʽ
//�ܹ���3���ַ�����12*12��16*16��24*24�����û������������������ֱ��ʵ��ַ�����
//ÿ���ַ���ռ�õ��ֽ���Ϊ:(size/8+((size%8)?1:0))*(size/2),����size:���ֿ�����ʱ�ĵ����С(12/16/24...)

  const unsigned char *p;
		
///////////////////////////////////////////////////////////////////////				
//      0-9   �ִ�
///////////////////////////////////////////////////////////////////////
//n_0   8*16
/*--  �`��:  0  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
const unsigned char n_0[]={
0xE0,0x18,0x04,0x04,0x04,0x18,0xE0,0x00,0x07,0x18,0x20,0x20,0x20,0x18,0x07,0x00,

/*--  �`��:  1  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x00,0x08,0xFC,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,

/*--  �`��:  2  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x18,0x04,0x04,0x04,0x04,0x88,0x70,0x00,0x30,0x28,0x24,0x22,0x21,0x20,0x30,0x00,

/*--  �`��:  3  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x08,0x84,0x84,0xC4,0x38,0x00,0x00,0x10,0x20,0x20,0x20,0x20,0x11,0x0E,0x00,

/*--  �`��:  4  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x80,0x60,0x18,0xFC,0x00,0x00,0x00,0x06,0x05,0x04,0x04,0x3F,0x04,0x04,0x00,

/*--  �`��:  5  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x7C,0x44,0x44,0x44,0x84,0x04,0x00,0x10,0x20,0x20,0x20,0x20,0x10,0x0F,0x00,

/*--  �`��:  6  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0xE0,0x90,0x48,0x44,0x44,0x84,0x00,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00,

/*--  �`��:  7  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x1C,0x04,0x04,0x04,0x04,0xE4,0x1C,0x00,0x00,0x00,0x00,0x38,0x07,0x00,0x00,0x00,

/*--  �`��:  8  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x30,0x48,0x84,0x84,0x84,0x48,0x30,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x0E,0x00,

/*--  �`��:  9  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00,0x00,0x21,0x22,0x22,0x12,0x09,0x07,0x00
}; 


/*////////////////////////////////////////////
//     ��̖
*//////////////////////////////////////////////
const unsigned char s_0[]={
//  n_dot   /*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=4x16   --*/
//const unsigned char n_dot[]={
0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00
};  

//  n_?  ��  /*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=7x16   --*/
const unsigned char n_wen[]={
0x00,0x38,0x04,0x04,0x84,0x78,0x00,0x00,0x00,0x00,0x36,0x01,0x00,0x00
};

/*////////////////////////////////////////////
//     english  �ִ�
*//////////////////////////////////////////////

const unsigned char e_0[]={
//const unsigned char eng_a[]={
/*--  �`��:  a  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=7x16   --*/
0x80,0x40,0x40,0x40,0x80,0x00,0x00,0x18,0x24,0x22,0x12,0x3F,0x20,0x00
};

const unsigned char eng_b[]={
/*--  �`��:  b  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x04,0xFC,0x80,0x40,0x40,0x80,0x00,0x00,0x00,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00
};

const unsigned char eng_c[]={
/*--  �`��:  c  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=7x16   --*/
0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x00
};

const unsigned char eng_d[]={
/*--  �`��:  d  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x80,0x40,0x40,0x84,0xFC,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x3F,0x20,0x00
};

const unsigned char eng_e[]={
/*--  �`��:  e  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=7x16   --*/
0x00,0x80,0x40,0x40,0x80,0x00,0x00,0x0F,0x12,0x22,0x22,0x22,0x13,0x00
};

const unsigned char eng_f[]={
/*--  �`��:  f  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=5x16   --*/
0x40,0xF8,0x44,0x48,0x00,0x20,0x3F,0x20,0x00,0x00
};

const unsigned char eng_g[]={
/*--  �`��:  g  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x80,0x40,0x40,0x40,0x80,0x40,0x00,0x40,0xB3,0xAC,0xA8,0xA4,0xA3,0x40,0x00
};

const unsigned char eng_h[]={
/*--  �`��:  h  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x08,0xFC,0x80,0x40,0x40,0x80,0x00,0x00,0x20,0x3F,0x20,0x00,0x20,0x3F,0x20,0x00
};

const unsigned char eng_i[]={
/*--  �`��:  i  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=4x16   --*/
0x80,0xCC,0x00,0x00,0x20,0x3F,0x20,0x00
};

const unsigned char eng_j[]={
/*--  �`��:  j  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=4x16   --*/
0x00,0x80,0xCC,0x00,0x80,0x80,0x7F,0x00
};

const unsigned char eng_k[]={
/*--  �`��:  k  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x04,0xFC,0x00,0x00,0xC0,0x40,0x00,0x00,0x20,0x3F,0x22,0x05,0x28,0x30,0x20,0x00
};

const unsigned char eng_l[]={
/*--  �`��:  l  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=4x16   --*/
0x04,0xFC,0x00,0x00,0x20,0x3F,0x20,0x00
};

const unsigned char eng_m[]={
/*--  �`��:  m  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=12x16   --*/
0x40,0x80,0x40,0x40,0x40,0x80,0x40,0x40,0x40,0x80,0x00,0x00,0x20,0x3F,0x20,0x00,
0x20,0x3F,0x20,0x00,0x20,0x3F,0x20,0x00
};

const unsigned char eng_n[]={
/*--  �`��:  n  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x40,0xC0,0x80,0x40,0x40,0x80,0x00,0x00,0x20,0x3F,0x20,0x00,0x20,0x3F,0x20,0x00
};

const unsigned char eng_o[]={
/*--  �`��:  o  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00
};

const unsigned char eng_p[]={
/*--  �`��:  p  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x40,0xC0,0x80,0x40,0x40,0x80,0x00,0x00,0x80,0xFF,0x90,0x20,0x20,0x10,0x0F,0x00
};

const unsigned char eng_q[]={
/*--  �`��:  q  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x80,0x40,0x40,0x80,0xC0,0x40,0x00,0x0F,0x10,0x20,0x20,0x90,0xFF,0x80,0x00
};

const unsigned char eng_r[]={
/*--  �`��:  r  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=5x16   --*/
0x40,0x80,0x40,0x40,0x00,0x20,0x3F,0x20,0x00,0x00
};

const unsigned char eng_s[]={
/*--  �`��:  s  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=6x16   --*/
0x80,0x40,0x40,0x40,0x80,0x00,0x19,0x22,0x22,0x24,0x19,0x00
};

const unsigned char eng_t[]={
/*--  �`��:  t  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=4x16   --*/
0x40,0xF0,0x40,0x00,0x00,0x3F,0x20,0x00
};

const unsigned char eng_u[]={
/*--  �`��:  u  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x40,0xC0,0x00,0x00,0x40,0xC0,0x00,0x00,0x00,0x1F,0x20,0x20,0x10,0x3F,0x20,0x00
};

const unsigned char eng_v[]={
/*--  �`��:  v  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x40,0xC0,0x40,0x00,0x40,0xC0,0x40,0x00,0x00,0x01,0x0E,0x30,0x0E,0x01,0x00,0x00
};

const unsigned char eng_w[]={
/*--  �`��:  w  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x40,0xC0,0x00,0x40,0xC0,0x00,0x40,0xC0,0x40,0x00,0x00,0x00,0x07,0x38,0x06,
0x01,0x06,0x38,0x07,0x00,0x00
};

const unsigned char eng_x[]={
/*--  �`��:  x  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x40,0xC0,0x40,0x00,0x40,0xC0,0x40,0x00,0x20,0x30,0x29,0x06,0x29,0x30,0x20,0x00
};

const unsigned char eng_y[]={
/*--  �`��:  y  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x40,0xC0,0x40,0x00,0x40,0xC0,0x40,0x00,0x80,0x81,0x4E,0x30,0x0E,0x01,0x00,0x00
};

const unsigned char eng_z[]={
/*--  �`��:  z  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=7x16   --*/
0xC0,0x40,0x40,0x40,0x40,0xC0,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00
};

const unsigned char eng_A[]={
/*--  �`��:  A  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x00,0x00,0x80,0x60,0x18,0x60,0x80,0x00,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,
0x02,0x02,0x23,0x3C,0x20,0x00
};

const unsigned char eng_B[]={
/*--  �`��:  B  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=10x16   --*/
0x00,0x08,0xF8,0x08,0x08,0x08,0x08,0x90,0x60,0x00,0x00,0x20,0x3F,0x21,0x21,0x21,
0x21,0x12,0x0C,0x00
};

const unsigned char eng_C[]={
/*--  �`��:  C  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=10x16   --*/
0x00,0xE0,0x10,0x08,0x08,0x08,0x08,0x10,0x38,0x00,0x00,0x0F,0x10,0x20,0x20,0x20,
0x20,0x20,0x10,0x00
};

const unsigned char eng_D[]={
/*--  �`��:  D  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x08,0xF8,0x08,0x08,0x08,0x08,0x10,0x20,0xC0,0x00,0x00,0x20,0x3F,0x20,0x20,
0x20,0x20,0x10,0x08,0x07,0x00
};

const unsigned char eng_E[]={
/*--  �`��:  E  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=9x16   --*/
0x00,0x08,0xF8,0x08,0x08,0x88,0x18,0x00,0x00,0x00,0x20,0x3F,0x21,0x21,0x23,0x30,
0x08,0x00
};

const unsigned char eng_F[]={
/*--  �`��:  F  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x08,0xF8,0x08,0x08,0x88,0x18,0x00,0x00,0x20,0x3F,0x21,0x01,0x03,0x00,0x00
};

const unsigned char eng_G[]={
/*--  �`��:  G  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0xE0,0x10,0x08,0x08,0x08,0x08,0x10,0x38,0x00,0x00,0x00,0x0F,0x10,0x20,0x20,
0x20,0x20,0x11,0x0F,0x01,0x00
};

const unsigned char eng_H[]={
/*--  �`��:  H  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x08,0xF8,0x08,0x00,0x00,0x00,0x08,0xF8,0x08,0x00,0x00,0x20,0x3F,0x21,0x01,
0x01,0x01,0x21,0x3F,0x20,0x00
};

const unsigned char eng_I[]={
/*--  �`��:  I  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=5x16   --*/
0x00,0x08,0xF8,0x08,0x00,0x00,0x20,0x3F,0x20,0x00
};

const unsigned char eng_J[]={
/*--  �`��:  J  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=6x16   --*/
0x00,0x00,0x04,0xFC,0x04,0x00,0x00,0x10,0x20,0x1F,0x00,0x00
};

const unsigned char eng_K[]={
/*--  �`��:  K  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x08,0xF8,0x08,0x80,0x40,0x28,0x18,0x08,0x00,0x00,0x00,0x20,0x3F,0x21,0x01,
0x02,0x04,0x28,0x30,0x20,0x00
};

const unsigned char eng_L[]={
/*--  �`��:  L  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=9x16   --*/
0x00,0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x30,
0x08,0x00
};

const unsigned char eng_M[]={
/*--  �`��:  M  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=13x16   --*/
0x00,0x08,0xF8,0x60,0x80,0x00,0x00,0x00,0x80,0x60,0xF8,0x08,0x00,0x00,0x20,0x3F,
0x20,0x03,0x0C,0x30,0x0C,0x03,0x20,0x3F,0x20,0x00
};

const unsigned char eng_N[]={
/*--  �`��:  N  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x08,0xF8,0x30,0xC0,0x00,0x00,0x08,0xF8,0x08,0x00,0x00,0x20,0x3F,0x20,0x00,
0x03,0x0C,0x10,0x3F,0x00,0x00
};

const unsigned char eng_O[]={
/*--  �`��:  O  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0xC0,0x30,0x08,0x08,0x08,0x08,0x08,0x30,0xC0,0x00,0x00,0x07,0x18,0x20,0x20,
0x20,0x20,0x20,0x18,0x07,0x00
};

const unsigned char eng_P[]={
/*--  �`��:  P  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x08,0xF8,0x08,0x08,0x90,0x60,0x00,0x00,0x20,0x3F,0x21,0x01,0x00,0x00,0x00
};

const unsigned char eng_Q[]={
/*--  �`��:  Q  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0xC0,0x30,0x08,0x08,0x08,0x08,0x08,0x30,0xC0,0x00,0x00,0x07,0x18,0x20,0x20,
0x60,0x60,0xA0,0x98,0x87,0x00
};

const unsigned char eng_R[]={
/*--  �`��:  R  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=10x16   --*/
0x00,0x08,0xF8,0x08,0x08,0x08,0x90,0x60,0x00,0x00,0x00,0x20,0x3F,0x21,0x03,0x05,
0x08,0x30,0x20,0x00
};

const unsigned char eng_S[]={
/*--  �`��:  S  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=8x16   --*/
0x00,0x60,0x90,0x08,0x08,0x10,0x38,0x00,0x00,0x38,0x10,0x21,0x21,0x12,0x0C,0x00
};

const unsigned char eng_T[]={
/*--  �`��:  T  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=9x16   --*/
0x00,0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,
0x00,0x00
};

const unsigned char eng_U[]={
/*--  �`��:  U  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x08,0xF8,0x08,0x00,0x00,0x00,0x08,0xF8,0x08,0x00,0x00,0x00,0x0F,0x10,0x20,
0x20,0x20,0x10,0x0F,0x00,0x00
};

const unsigned char eng_V[]={
/*--  �`��:  V  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x08,0x38,0xC8,0x00,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x00,0x01,0x0E,
0x30,0x0E,0x01,0x00,0x00,0x00
};

const unsigned char eng_W[]={
/*--  �`��:  W  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=14x16   --*/
0x00,0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0xC8,0x00,0x88,0x78,0x08,0x00,0x00,0x00,
0x00,0x07,0x38,0x07,0x00,0x00,0x07,0x38,0x07,0x00,0x00,0x00
};

const unsigned char eng_X[]={
/*--  �`��:  X  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x08,0x18,0x28,0xC0,0x00,0xC0,0x28,0x18,0x08,0x00,0x00,0x20,0x30,0x28,0x06,
0x01,0x06,0x28,0x30,0x20,0x00
};

const unsigned char eng_Y[]={
/*--  �`��:  Y  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=11x16   --*/
0x00,0x08,0x18,0x68,0x80,0x00,0x80,0x68,0x18,0x08,0x00,0x00,0x00,0x00,0x00,0x20,
0x3F,0x20,0x00,0x00,0x00,0x00
};

const unsigned char eng_Z[]={
/*--  �`��:  Z  --*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=9x16   --*/
0x00,0x38,0x08,0x08,0x88,0x68,0x18,0x00,0x00,0x00,0x30,0x2C,0x23,0x20,0x20,0x30,
0x08,0x00
};




 
/*���w����*/

const unsigned char t_0[]={
/*--  �`��:  �  0--*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=16x16   --*/
0x00,0x20,0x1C,0xA8,0xAA,0xAA,0x4A,0x0A,0xFE,0x0A,0x4A,0xAA,0xAA,0xA8,0x1C,0x08,
0x00,0x00,0x00,0x00,0x3E,0x2A,0x2A,0x2A,0xFE,0xAA,0xAA,0xAA,0xBE,0x80,0xF0,0x40,	

/*--  �`��:  ��  1--*/
/*--  �¼����w12;  ɭ�¼��B����ǻ���ǍR����xԃ=16x16   --*/	
0x00,0x20,0xC2,0x0C,0x00,0x88,0xC8,0xA8,0x98,0x8C,0x4A,0x48,0x58,0x68,0xCC,0x08,
0x00,0xC0,0x30,0x0C,0x80,0x40,0x3E,0x02,0x00,0x7E,0x02,0x00,0x7E,0x82,0x80,0x80,
};

/*���w����*/

const unsigned char c_0[]={
/*--  ��?ً�����Z����C:\Users\james\Desktop\batttest2\��ģ�D�n\china\C_1.bmp  --*/
/*--  ��Hxԃ�H=16x16  --*/
0x00,0x08,0x04,0xC3,0x12,0x26,0x8A,0xA2,0xAA,0xA4,0xA3,0x22,0x26,0xEA,0x02,0x02,
0x00,0x00,0x00,0xFF,0x00,0x00,0x3F,0x24,0x24,0x24,0x3F,0x00,0x80,0xFF,0x00,0x00,	

/*--  ��?ً�����Z����C:\Users\james\Desktop\batttest2\��ģ�D�n\china\C_3.bmp  --*/
/*--  ��Hxԃ�H=16x16  --*/
0x00,0x40,0x40,0x42,0xCC,0x00,0x10,0x10,0x10,0x90,0x7F,0x90,0x10,0x10,0x10,0x10,
0x00,0x00,0x40,0x20,0x1F,0x20,0x48,0x44,0x42,0x41,0x40,0x40,0x41,0x42,0x4C,0x40,
};


/*��������*/

const unsigned char j_0[]={
/*--  ��?ً�����Z����C:\Users\james\Desktop\batttest2\��ģ�D�n\JANPAN\132.bmp  --*/
/*--  ��Hxԃ�H=16x16  --*/
0x00,0x00,0x00,0x00,0xC0,0x38,0x00,0x00,0x18,0x60,0x84,0x08,0x00,0x04,0x08,0x00,
0x00,0x20,0x18,0x06,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x18,0x20,0x00,0x00,	

/*--  ��?ً�����Z����C:\Users\james\Desktop\batttest2\��ģ�D�n\JANPAN\133.bmp  --*/
/*--  ��Hxԃ�H=16x16  --*/
0x00,0x00,0x00,0xC0,0x00,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0xC0,0x40,0x00,0x00,
0x00,0x00,0x00,0x01,0x00,0x40,0x41,0x20,0x20,0x10,0x08,0x06,0x01,0x00,0x00,0x00,
};


/*�n������*/

const unsigned char k_0[]={
/*--  ��?ً�����Z����C:\Users\james\Desktop\batttest2\��ģ�D�n\korea\K_1.bmp  --*/
/*--  ��Hxԃ�H=64x16  --*/
0x00,0x00,0x82,0x42,0x32,0x0E,0x32,0x42,0x82,0x02,0x00,0x00,0xFE,0x00,0x00,0x00,
0x00,0xFC,0x02,0x02,0x02,0x02,0x02,0x02,0x80,0x80,0x00,0xFE,0x20,0x20,0x00,0x00,
0x00,0x08,0xC8,0x2A,0x2A,0x2A,0x2A,0x2A,0xC8,0x08,0x00,0x00,0xFE,0x10,0x10,0x00,
0x00,0x00,0x80,0x9E,0x92,0x92,0x92,0x92,0xF2,0x92,0x92,0x92,0x92,0x9E,0x80,0x00,
0x00,0x01,0x00,0x38,0x40,0x40,0x40,0x40,0x40,0x41,0x40,0x40,0x47,0x00,0x00,0x00,
0x00,0x00,0x39,0x41,0x41,0x41,0x41,0x41,0x40,0x40,0x40,0x47,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x11,0x29,0x45,0x45,0x45,0x44,0x44,0x44,0x28,0x13,0x00,0x00,0x00,
0x00,0x00,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x78,0x00,0x00,	
	
/*--  ��?ً�����Z����C:\Users\james\Desktop\batttest2\��ģ�D�n\korea\K_2.bmp  --*/
/*--  ��Hxԃ�H=14x16  --*/
0x00,0x00,0x80,0x40,0x30,0x1E,0x20,0x40,0x90,0x10,0x10,0x10,0xFE,0x00,0x00,0x01,
0x00,0x38,0x40,0x40,0x40,0x40,0x40,0x41,0x40,0x40,0x4F,0x00,	
	

/*--  ��?ً�����Z����C:\Users\james\Desktop\batttest2\��ģ�D�n\korea\K_3.bmp  --*/
/*--  ��Hxԃ�H=46x16  --*/
0x00,0xFC,0x40,0x40,0x40,0x40,0xFC,0x00,0x00,0xFE,0x80,0x80,0xFE,0x00,0x00,0x00,
0x00,0xF8,0x84,0x84,0x84,0x84,0x84,0x04,0x80,0x80,0x80,0xFE,0x00,0x00,0x00,0x00,
0x00,0x00,0x04,0x84,0x84,0x84,0x84,0x84,0x78,0x00,0x00,0x00,0xFE,0x00,0x00,0x0F,
0x10,0x10,0x10,0x10,0x0F,0x00,0x00,0x7F,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x0F,
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,
0x0F,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x7F,0x00,

/*--  ��?ً�����Z����C:\Users\james\Desktop\batttest2\��ģ�D�n\korea\K_4.bmp  --*/
/*--  ��Hxԃ�H=46x16  --*/
0x00,0x7E,0x90,0x90,0x90,0x90,0x90,0x7E,0x00,0x00,0x00,0xFE,0x10,0x10,0x00,0x00,
0x00,0x82,0x42,0x32,0x0E,0x32,0x42,0x92,0x12,0x10,0x10,0xFE,0x00,0x00,0x00,0x00,
0x00,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0xF8,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,
0x32,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x44,0x00,0x00,0x00,0x00,0x01,0x00,
0x38,0x40,0x40,0x40,0x40,0x40,0x41,0x40,0x40,0x4F,0x00,0x00,0x00,0x00,0x00,0x10,
0x10,0x10,0x08,0x08,0x04,0x03,0x00,0x00,0x00,0x00,0x7F,0x00,

};



 
//16*16 ASCII�ַ�������
const unsigned char asc2_1608[95][16]={	  
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xCC,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00},/*"!",1*/
{0x00,0x00,0x08,0x00,0x30,0x00,0x60,0x00,0x08,0x00,0x30,0x00,0x60,0x00,0x00,0x00},/*""",2*/
{0x02,0x20,0x03,0xFC,0x1E,0x20,0x02,0x20,0x03,0xFC,0x1E,0x20,0x02,0x20,0x00,0x00},/*"#",3*/
{0x00,0x00,0x0E,0x18,0x11,0x04,0x3F,0xFF,0x10,0x84,0x0C,0x78,0x00,0x00,0x00,0x00},/*"$",4*/
{0x0F,0x00,0x10,0x84,0x0F,0x38,0x00,0xC0,0x07,0x78,0x18,0x84,0x00,0x78,0x00,0x00},/*"%",5*/
{0x00,0x78,0x0F,0x84,0x10,0xC4,0x11,0x24,0x0E,0x98,0x00,0xE4,0x00,0x84,0x00,0x08},/*"&",6*/
{0x08,0x00,0x68,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0x18,0x18,0x20,0x04,0x40,0x02,0x00,0x00},/*"(",8*/
{0x00,0x00,0x40,0x02,0x20,0x04,0x18,0x18,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00},/*")",9*/
{0x02,0x40,0x02,0x40,0x01,0x80,0x0F,0xF0,0x01,0x80,0x02,0x40,0x02,0x40,0x00,0x00},/*"*",10*/
{0x00,0x80,0x00,0x80,0x00,0x80,0x0F,0xF8,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x00},/*"+",11*/
{0x00,0x01,0x00,0x0D,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*",",12*/
{0x00,0x00,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80},/*"-",13*/
{0x00,0x00,0x00,0x0C,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*".",14*/
{0x00,0x00,0x00,0x06,0x00,0x18,0x00,0x60,0x01,0x80,0x06,0x00,0x18,0x00,0x20,0x00},/*"/",15*/
{0x00,0x00,0x07,0xF0,0x08,0x08,0x10,0x04,0x10,0x04,0x08,0x08,0x07,0xF0,0x00,0x00},/*"0",16*/
{0x00,0x00,0x08,0x04,0x08,0x04,0x1F,0xFC,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00},/*"1",17*/
{0x00,0x00,0x0E,0x0C,0x10,0x14,0x10,0x24,0x10,0x44,0x11,0x84,0x0E,0x0C,0x00,0x00},/*"2",18*/
{0x00,0x00,0x0C,0x18,0x10,0x04,0x11,0x04,0x11,0x04,0x12,0x88,0x0C,0x70,0x00,0x00},/*"3",19*/
{0x00,0x00,0x00,0xE0,0x03,0x20,0x04,0x24,0x08,0x24,0x1F,0xFC,0x00,0x24,0x00,0x00},/*"4",20*/
{0x00,0x00,0x1F,0x98,0x10,0x84,0x11,0x04,0x11,0x04,0x10,0x88,0x10,0x70,0x00,0x00},/*"5",21*/
{0x00,0x00,0x07,0xF0,0x08,0x88,0x11,0x04,0x11,0x04,0x18,0x88,0x00,0x70,0x00,0x00},/*"6",22*/
{0x00,0x00,0x1C,0x00,0x10,0x00,0x10,0xFC,0x13,0x00,0x1C,0x00,0x10,0x00,0x00,0x00},/*"7",23*/
{0x00,0x00,0x0E,0x38,0x11,0x44,0x10,0x84,0x10,0x84,0x11,0x44,0x0E,0x38,0x00,0x00},/*"8",24*/
{0x00,0x00,0x07,0x00,0x08,0x8C,0x10,0x44,0x10,0x44,0x08,0x88,0x07,0xF0,0x00,0x00},/*"9",25*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0C,0x03,0x0C,0x00,0x00,0x00,0x00,0x00,0x00},/*":",26*/
{0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*";",27*/
{0x00,0x00,0x00,0x80,0x01,0x40,0x02,0x20,0x04,0x10,0x08,0x08,0x10,0x04,0x00,0x00},/*"<",28*/
{0x02,0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x02,0x20,0x00,0x00},/*"=",29*/
{0x00,0x00,0x10,0x04,0x08,0x08,0x04,0x10,0x02,0x20,0x01,0x40,0x00,0x80,0x00,0x00},/*">",30*/
{0x00,0x00,0x0E,0x00,0x12,0x00,0x10,0x0C,0x10,0x6C,0x10,0x80,0x0F,0x00,0x00,0x00},/*"?",31*/
{0x03,0xE0,0x0C,0x18,0x13,0xE4,0x14,0x24,0x17,0xC4,0x08,0x28,0x07,0xD0,0x00,0x00},/*"@",32*/
{0x00,0x04,0x00,0x3C,0x03,0xC4,0x1C,0x40,0x07,0x40,0x00,0xE4,0x00,0x1C,0x00,0x04},/*"A",33*/
{0x10,0x04,0x1F,0xFC,0x11,0x04,0x11,0x04,0x11,0x04,0x0E,0x88,0x00,0x70,0x00,0x00},/*"B",34*/
{0x03,0xE0,0x0C,0x18,0x10,0x04,0x10,0x04,0x10,0x04,0x10,0x08,0x1C,0x10,0x00,0x00},/*"C",35*/
{0x10,0x04,0x1F,0xFC,0x10,0x04,0x10,0x04,0x10,0x04,0x08,0x08,0x07,0xF0,0x00,0x00},/*"D",36*/
{0x10,0x04,0x1F,0xFC,0x11,0x04,0x11,0x04,0x17,0xC4,0x10,0x04,0x08,0x18,0x00,0x00},/*"E",37*/
{0x10,0x04,0x1F,0xFC,0x11,0x04,0x11,0x00,0x17,0xC0,0x10,0x00,0x08,0x00,0x00,0x00},/*"F",38*/
{0x03,0xE0,0x0C,0x18,0x10,0x04,0x10,0x04,0x10,0x44,0x1C,0x78,0x00,0x40,0x00,0x00},/*"G",39*/
{0x10,0x04,0x1F,0xFC,0x10,0x84,0x00,0x80,0x00,0x80,0x10,0x84,0x1F,0xFC,0x10,0x04},/*"H",40*/
{0x00,0x00,0x10,0x04,0x10,0x04,0x1F,0xFC,0x10,0x04,0x10,0x04,0x00,0x00,0x00,0x00},/*"I",41*/
{0x00,0x03,0x00,0x01,0x10,0x01,0x10,0x01,0x1F,0xFE,0x10,0x00,0x10,0x00,0x00,0x00},/*"J",42*/
{0x10,0x04,0x1F,0xFC,0x11,0x04,0x03,0x80,0x14,0x64,0x18,0x1C,0x10,0x04,0x00,0x00},/*"K",43*/
{0x10,0x04,0x1F,0xFC,0x10,0x04,0x00,0x04,0x00,0x04,0x00,0x04,0x00,0x0C,0x00,0x00},/*"L",44*/
{0x10,0x04,0x1F,0xFC,0x1F,0x00,0x00,0xFC,0x1F,0x00,0x1F,0xFC,0x10,0x04,0x00,0x00},/*"M",45*/
{0x10,0x04,0x1F,0xFC,0x0C,0x04,0x03,0x00,0x00,0xE0,0x10,0x18,0x1F,0xFC,0x10,0x00},/*"N",46*/
{0x07,0xF0,0x08,0x08,0x10,0x04,0x10,0x04,0x10,0x04,0x08,0x08,0x07,0xF0,0x00,0x00},/*"O",47*/
{0x10,0x04,0x1F,0xFC,0x10,0x84,0x10,0x80,0x10,0x80,0x10,0x80,0x0F,0x00,0x00,0x00},/*"P",48*/
{0x07,0xF0,0x08,0x18,0x10,0x24,0x10,0x24,0x10,0x1C,0x08,0x0A,0x07,0xF2,0x00,0x00},/*"Q",49*/
{0x10,0x04,0x1F,0xFC,0x11,0x04,0x11,0x00,0x11,0xC0,0x11,0x30,0x0E,0x0C,0x00,0x04},/*"R",50*/
{0x00,0x00,0x0E,0x1C,0x11,0x04,0x10,0x84,0x10,0x84,0x10,0x44,0x1C,0x38,0x00,0x00},/*"S",51*/
{0x18,0x00,0x10,0x00,0x10,0x04,0x1F,0xFC,0x10,0x04,0x10,0x00,0x18,0x00,0x00,0x00},/*"T",52*/
{0x10,0x00,0x1F,0xF8,0x10,0x04,0x00,0x04,0x00,0x04,0x10,0x04,0x1F,0xF8,0x10,0x00},/*"U",53*/
{0x10,0x00,0x1E,0x00,0x11,0xE0,0x00,0x1C,0x00,0x70,0x13,0x80,0x1C,0x00,0x10,0x00},/*"V",54*/
{0x1F,0xC0,0x10,0x3C,0x00,0xE0,0x1F,0x00,0x00,0xE0,0x10,0x3C,0x1F,0xC0,0x00,0x00},/*"W",55*/
{0x10,0x04,0x18,0x0C,0x16,0x34,0x01,0xC0,0x01,0xC0,0x16,0x34,0x18,0x0C,0x10,0x04},/*"X",56*/
{0x10,0x00,0x1C,0x00,0x13,0x04,0x00,0xFC,0x13,0x04,0x1C,0x00,0x10,0x00,0x00,0x00},/*"Y",57*/
{0x08,0x04,0x10,0x1C,0x10,0x64,0x10,0x84,0x13,0x04,0x1C,0x04,0x10,0x18,0x00,0x00},/*"Z",58*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFE,0x40,0x02,0x40,0x02,0x40,0x02,0x00,0x00},/*"[",59*/
{0x00,0x00,0x30,0x00,0x0C,0x00,0x03,0x80,0x00,0x60,0x00,0x1C,0x00,0x03,0x00,0x00},/*"\",60*/
{0x00,0x00,0x40,0x02,0x40,0x02,0x40,0x02,0x7F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00},/*"]",61*/
{0x00,0x00,0x00,0x00,0x20,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x20,0x00,0x00,0x00},/*"^",62*/
{0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01},/*"_",63*/
{0x00,0x00,0x40,0x00,0x40,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
{0x00,0x00,0x00,0x98,0x01,0x24,0x01,0x44,0x01,0x44,0x01,0x44,0x00,0xFC,0x00,0x04},/*"a",65*/
{0x10,0x00,0x1F,0xFC,0x00,0x88,0x01,0x04,0x01,0x04,0x00,0x88,0x00,0x70,0x00,0x00},/*"b",66*/
{0x00,0x00,0x00,0x70,0x00,0x88,0x01,0x04,0x01,0x04,0x01,0x04,0x00,0x88,0x00,0x00},/*"c",67*/
{0x00,0x00,0x00,0x70,0x00,0x88,0x01,0x04,0x01,0x04,0x11,0x08,0x1F,0xFC,0x00,0x04},/*"d",68*/
{0x00,0x00,0x00,0xF8,0x01,0x44,0x01,0x44,0x01,0x44,0x01,0x44,0x00,0xC8,0x00,0x00},/*"e",69*/
{0x00,0x00,0x01,0x04,0x01,0x04,0x0F,0xFC,0x11,0x04,0x11,0x04,0x11,0x00,0x18,0x00},/*"f",70*/
{0x00,0x00,0x00,0xD6,0x01,0x29,0x01,0x29,0x01,0x29,0x01,0xC9,0x01,0x06,0x00,0x00},/*"g",71*/
{0x10,0x04,0x1F,0xFC,0x00,0x84,0x01,0x00,0x01,0x00,0x01,0x04,0x00,0xFC,0x00,0x04},/*"h",72*/
{0x00,0x00,0x01,0x04,0x19,0x04,0x19,0xFC,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00},/*"i",73*/
{0x00,0x00,0x00,0x03,0x00,0x01,0x01,0x01,0x19,0x01,0x19,0xFE,0x00,0x00,0x00,0x00},/*"j",74*/
{0x10,0x04,0x1F,0xFC,0x00,0x24,0x00,0x40,0x01,0xB4,0x01,0x0C,0x01,0x04,0x00,0x00},/*"k",75*/
{0x00,0x00,0x10,0x04,0x10,0x04,0x1F,0xFC,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00},/*"l",76*/
{0x01,0x04,0x01,0xFC,0x01,0x04,0x01,0x00,0x01,0xFC,0x01,0x04,0x01,0x00,0x00,0xFC},/*"m",77*/
{0x01,0x04,0x01,0xFC,0x00,0x84,0x01,0x00,0x01,0x00,0x01,0x04,0x00,0xFC,0x00,0x04},/*"n",78*/
{0x00,0x00,0x00,0xF8,0x01,0x04,0x01,0x04,0x01,0x04,0x01,0x04,0x00,0xF8,0x00,0x00},/*"o",79*/
{0x01,0x01,0x01,0xFF,0x00,0x85,0x01,0x04,0x01,0x04,0x00,0x88,0x00,0x70,0x00,0x00},/*"p",80*/
{0x00,0x00,0x00,0x70,0x00,0x88,0x01,0x04,0x01,0x04,0x01,0x05,0x01,0xFF,0x00,0x01},/*"q",81*/
{0x01,0x04,0x01,0x04,0x01,0xFC,0x00,0x84,0x01,0x04,0x01,0x00,0x01,0x80,0x00,0x00},/*"r",82*/
{0x00,0x00,0x00,0xCC,0x01,0x24,0x01,0x24,0x01,0x24,0x01,0x24,0x01,0x98,0x00,0x00},/*"s",83*/
{0x00,0x00,0x01,0x00,0x01,0x00,0x07,0xF8,0x01,0x04,0x01,0x04,0x00,0x00,0x00,0x00},/*"t",84*/
{0x01,0x00,0x01,0xF8,0x00,0x04,0x00,0x04,0x00,0x04,0x01,0x08,0x01,0xFC,0x00,0x04},/*"u",85*/
{0x01,0x00,0x01,0x80,0x01,0x70,0x00,0x0C,0x00,0x10,0x01,0x60,0x01,0x80,0x01,0x00},/*"v",86*/
{0x01,0xF0,0x01,0x0C,0x00,0x30,0x01,0xC0,0x00,0x30,0x01,0x0C,0x01,0xF0,0x01,0x00},/*"w",87*/
{0x00,0x00,0x01,0x04,0x01,0x8C,0x00,0x74,0x01,0x70,0x01,0x8C,0x01,0x04,0x00,0x00},/*"x",88*/
{0x01,0x01,0x01,0x81,0x01,0x71,0x00,0x0E,0x00,0x18,0x01,0x60,0x01,0x80,0x01,0x00},/*"y",89*/
{0x00,0x00,0x01,0x84,0x01,0x0C,0x01,0x34,0x01,0x44,0x01,0x84,0x01,0x0C,0x00,0x00},/*"z",90*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x3E,0xFC,0x40,0x02,0x40,0x02},/*"{",91*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00},/*"|",92*/
{0x00,0x00,0x40,0x02,0x40,0x02,0x3E,0xFC,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"}",93*/
{0x00,0x00,0x60,0x00,0x80,0x00,0x80,0x00,0x40,0x00,0x40,0x00,0x20,0x00,0x20,0x00},/*"~",94*/
};  

	

const unsigned char logo_bmp[]={
	
/*--  ��?ً�����Z����C:\Users\james\Desktop\batt24v\battprint24_all_2\bbpprog\��ģ�D�n\ecpal_taiwan.bmp  --*/
/*--  ��Hxԃ�H=128x64  --*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x40,0x40,0x40,0x40,0x40,0x40,0x00,
0x80,0xC0,0x40,0x40,0x40,0x40,0x40,0xC0,0x80,0x00,0xC0,0x40,0x40,0x40,0x40,0x40,
0x40,0x40,0x80,0x00,0x00,0x00,0x80,0x40,0x80,0x00,0x00,0x00,0x00,0xC0,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,
0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0x60,0x20,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,
0xC0,0xE0,0xE0,0xF0,0xF0,0xF8,0xF8,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,
0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xF8,0xF8,0xF8,0xF8,0xF0,0xF0,0xE0,0xE0,0xC0,0x80,
0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x12,0x12,0x12,0x12,0x12,0x12,0x00,
0x0F,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x00,0x1F,0x04,0x04,0x04,0x04,0x04,
0x04,0x02,0x01,0x18,0x0C,0x0B,0x08,0x08,0x09,0x0B,0x0C,0x18,0x00,0x1F,0x10,0x10,
0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x10,0x18,0x1C,0x1E,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x0F,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,0xFF,0x7F,
0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFE,0xFC,0xF8,0xF0,0xC0,0x01,0x07,0x0C,0x30,0x60,0x60,0x30,0x0C,0x03,
0x01,0x00,0x7F,0x49,0x49,0x49,0x49,0x49,0x49,0x00,0x7F,0x08,0x08,0x08,0x08,0x08,
0x08,0x08,0x7F,0x00,0x00,0x7F,0x00,0x00,0x7F,0x41,0x41,0x41,0x41,0x41,0x41,0x63,
0x00,0x00,0x7F,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x7F,0x49,0x49,0x49,0x49,0x49,
0x49,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, 
0x00,0x00,0x00,0x00,0x80,0xF8,0xFE,0x3F,0x0F,0x07,0x03,0x01,0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x1F,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x80,0xC0,0xE0,0xE0,0xF0,0xF8,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,
0xFC,0xFC,0x7C,0x3C,0x1C,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x7F,0xFF,0xC1,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xC1,
0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,
0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF3,0xF0,0xF0,0xF0,0xE0,0xC0,0x80,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF8,
0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x03,
0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x07,0x1F,0x7F,0xFC,0xF8,0xF0,0xE0,0xE0,0xC0,0xC0,0x80,
0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xC0,0xC0,0xE0,0xE0,0xF0,0xF8,0xFC,0xFE,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3F,0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFE,0xFC,0xFC,0xF8,0xF0,0xF8,0xFC,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x1F,0x3F,0x7F,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,
0x3F,0x3F,0x1F,0x0F,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x1F,
0x3F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x7F,0x3F,0x1F,0x0F,0x07,0x03,0x01,
0x00,0x00,0x00,0x00,0x00,0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x80,0x80,
0x00,0x00,0x00,0x00,0x88,0x00,0x00,0x80,0x80,0x00,0x80,0x80,0x00,0x80,0x80,0x80,
0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x01,0x01,0x03,0x03,0x07,0x07,0x07,0x07,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,
0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x07,0x07,0x07,0x03,0x03,0x01,0x01,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,0x19,0x24,0x24,
0x1F,0x20,0x00,0x21,0x3F,0x20,0x00,0x00,0x0F,0x30,0x0C,0x03,0x0C,0x30,0x0F,0x00,
0x00,0x19,0x24,0x24,0x1F,0x20,0x00,0x20,0x3F,0x00,0x20,0x3F,0x20,0x00,0x00,0x00
};
const unsigned char jtc_6721[]={
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
0xE0,0xF0,0xF8,0xFE,0xFF,0xFF,0x7F,0x3F,0x1F,0x07,0x83,0xE0,0xF0,0xF8,0xFE,0xFF,
0xFF,0xFF,0x3F,0x1F,0x07,0x83,0xC0,0xF0,0xF8,0xFE,0xFF,0xFF,0xFF,0x7F,0x1F,0x0F,
0x87,0xC1,0xF0,0xF8,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x1F,0x0F,0x07,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xF0,0xF8,0xFC,0xFF,0xFF,
0xFF,0x3F,0x1F,0x0F,0x83,0xC1,0xF0,0xF8,0xFC,0xFF,0xFF,0xFF,0x3F,0x1F,0x0F,0x83,
0xC1,0xF0,0xF8,0xFC,0xFF,0xFF,0xFF,0x7F,0x3F,0x0F,0x07,0x03,0x00,0x00,0x00,0x00,
0x00,0x00,0x80,0xC0,0xF0,0xF8,0xFC,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x0F,
0x07,0x83,0xE0,0xF0,0xF8,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x1F,0x0F,0x87,
0xC1,0xF0,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x07,0x07,0x03,
0x03,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x80,0xC0,0xE0,0xF8,0xFC,0xFF,0xFF,0xFF,0x7F,0x1F,0x0F,0x83,0xC1,
0xE0,0xF8,0xFC,0xFE,0xFF,0xFF,0x7F,0x1F,0x0F,0x83,0xC1,0xE0,0xF8,0xFC,0xFF,0xFF,
0xFF,0x7F,0x3F,0x0F,0x07,0xE3,0xF0,0xF8,0xFE,0xFF,0xFF,0xF8,0xF0,0xF0,0xF8,0xF8,
0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x1F,0x0F,0x83,0xC1,0xF0,0xF8,0xFE,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x3F,0x0F,0x07,0x01,0x00,0x00,0x00,0xFE,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE1,0xE0,0xC0,0xC0,0xC0,0xE0,0xE0,0x60,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xE0,
0xF8,0xFC,0xFE,0xFF,0xFF,0x7F,0x3F,0x0F,0x07,0xC1,0xE0,0xF0,0xFC,0xFE,0xFF,0xFF,
0x7F,0x1F,0x0F,0x07,0xC1,0xE0,0xF8,0xFC,0xFE,0xFF,0xFF,0x7F,0x3F,0x1F,0x07,0x03,
0x01,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0F,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x0F,0x07,0x07,0x03,0x01,0x00,0x18,0x1C,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
0x1F,0x1F,0x0F,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,
0x07,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x0F,0x07,0x01,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF0,0xFC,0xFE,0xFF,0xFF,0x7F,
0x3F,0x0F,0x07,0x83,0xE0,0xF0,0xFC,0xFE,0xFF,0xFF,0x7F,0x3F,0x0F,0x07,0xC3,0xE0,
0xF0,0xFC,0xFE,0xFF,0xFF,0xFF,0x3F,0x1F,0x0F,0x83,0xC1,0xF0,0x98,0xFC,0x7E,0x1E,
0x82,0xE0,0x70,0x1C,0x8E,0xC2,0x70,0x3C,0x0E,0x82,0xE0,0x7C,0x1E,0x0E,0xC6,0xE6,
0x30,0x18,0x0C,0x86,0xEE,0x7E,0x1E,0x00,0x00,0x00,0x00,0x80,0xE0,0x7C,0x1E,0x8E,
0xE6,0x76,0x38,0x0C,0x8C,0xC6,0x7E,0x3E,0xCE,0xE0,0x30,0x18,0x0C,0x86,0xEE,0x7E,
0x9E,0xE0,0x70,0x3C,0x0E,0x02,0x00,0x70,0xF8,0xFC,0x66,0x06,0x06,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x07,0x07,0x07,0x07,0x07,0x07,0x03,0x01,0x00,
0x00,0x06,0x07,0x07,0x07,0x07,0x07,0x07,0x03,0x00,0x00,0x04,0x06,0x07,0x07,0x07,
0x07,0x07,0x07,0x03,0x01,0x00,0x04,0x06,0x03,0x01,0x01,0x07,0x07,0x03,0x00,0x06,
0x07,0x07,0x06,0x07,0x03,0x01,0x00,0x04,0x06,0x03,0x01,0x00,0x00,0x07,0x07,0x07,
0x06,0x02,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x04,0x06,0x03,0x01,0x00,0x00,0x07,
0x07,0x06,0x06,0x03,0x03,0x01,0x00,0x07,0x07,0x07,0x06,0x02,0x03,0x01,0x04,0x06,
0x07,0x07,0x06,0x02,0x06,0x07,0x06,0x02,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0xFE,0xFE,0xFE,0x00,0x00,0x00,0x00,0x06,0x06,0x06,0x06,0xFE,0xFE,0xFE,
0x06,0x06,0x06,0x06,0x06,0x00,0x00,0xE0,0xF8,0xFC,0x3E,0x0E,0x07,0x07,0x07,0x0E,
0x1E,0x3E,0x1C,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,
0xFC,0xFC,0x9E,0xC6,0xC6,0xCE,0xDE,0x9C,0x08,0x00,0x00,0x00,0x0E,0x0E,0x0E,0x0E,
0xCE,0xEE,0xFE,0x3E,0x0E,0x06,0x00,0x00,0x10,0x1C,0x1E,0x1E,0x06,0x06,0x8E,0xFE,
0xFE,0x7C,0x00,0x00,0x00,0x00,0x70,0x70,0x38,0x3C,0xFE,0xFE,0xFE,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x78,0xF8,0xE0,
0xE0,0xE0,0xFF,0x7F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x3F,0x7F,0x78,0xF0,0xE0,0xE0,0xE0,0xE0,
0xF8,0x7C,0x38,0x18,0x00,0x00,0x00,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x00,0x00,0x1F,
0x3F,0x7F,0xF3,0xE0,0xE0,0xE1,0xFF,0x7F,0x3F,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF,
0x7F,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xF0,0xF8,0xFC,0xFE,0xEF,0xE7,0xE3,
0xE1,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#endif

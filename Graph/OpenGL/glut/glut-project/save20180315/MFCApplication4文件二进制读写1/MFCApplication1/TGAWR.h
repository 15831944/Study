#pragma once
#include"stdafx.h"

#ifndef __TEXTURE_H__    // ������ͷ�ļ��Ƿ��Ѿ�������
#define __TEXTURE_H__    // ���û�У�������


//����ṹ�嶨��  
typedef struct
{
	GLubyte *imageData;//ͼ������  
	GLuint bpp;//�������  
	GLuint width;//ͼ����  
	GLuint height;//ͼ��߶�  
	GLuint texID;//��Ӧ������ID  
	GLuint type;     // �����洢��*ImageData�е�����(GL_RGB Or GL_RGBA)
}TextureImage;



typedef struct
{
	GLubyte Header[12];   // �ļ�ͷ�����ļ�����
	GLuint Header1;   // �ļ�ͷ�����ļ�����
} TGAHeader;




typedef struct
{
	GLubyte header[12];    // ����ǰ6���ֽ�
	//int header[6];    // ����ǰ6���ֽ�
	GLuint bytesPerPixel;   // ÿ���ص��ֽ��� (3 �� 4)
	GLuint imageSize;    // ���ƴ洢ͼ��������ڴ�ռ�
	GLuint type;    // ͼ������ GL_RGB �� GL_RGBA
	GLuint Height;    // ͼ��ĸ߶�
	GLuint Width;    // ͼ����
	GLuint Bpp;    // ÿ���صı����� (24 �� 32)
} TGA;




class CTGAWR
{
public:
	CTGAWR();
	~CTGAWR();


public:

	
	
	TGAHeader tgaheader;    // �����洢���ǵ��ļ�ͷ


	
	

	TGA tga;      // �����洢�ļ���Ϣ

	CFile cfile;

				  // δѹ����TGAͷ
	GLubyte uTGAcompare[12] = { 0,0,2,0,0,0,0,0,0,0,0,0 };
	// ѹ����TGAͷ
	GLubyte cTGAcompare[12] = { 0,0,10,0,0,0,0,0,0,0,0,0 };



	
	
public:

	//TGAͷ�ȽϺ���
	bool TGAHeaderCompare(GLubyte* TGACompare, GLubyte* HeaderCompare);

	////����TGAͼ����ѹ����ʽ������������ 
	bool LoadTGA(TextureImage* texture, CString cfilename);
	// ��ȡһ��δѹ�����ļ�
	bool LoadUncompressedTGA(TextureImage* texture);
	// ��ȡһ��ѹ�����ļ�
	bool LoadCompressedTGA(TextureImage* texture);

	GLint gltWriteTGA(const char* szFileName);



	









	
};

#endif      // __TEXTURE_H__ ������������
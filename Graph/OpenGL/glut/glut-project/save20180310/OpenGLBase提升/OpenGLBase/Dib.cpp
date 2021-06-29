#include "stdafx.h"
#include "Dib.h"
#include"windowsX.h"

CDib::CDib()
{
	m_pBmFileHeader = NULL;
	m_pBmInfo = NULL;
	m_pBmInfoHeader = NULL;
	m_pRGBTable = 0;
	m_numColors = 0;
}

CDib::CDib(const CString fileName)
{
	/*װ��λͼ*/
	LoadBitmapFile(fileName);
}

CDib::~CDib()
{
	GlobalFreePtr(m_pBmInfo);
}


BYTE* CDib::GetDibBitsPtr()
{
	return m_pDibBits;
}


LPBITMAPINFO CDib::GetDibInfoPtr()
{
	return m_pBmInfo;
}


LPBITMAPINFOHEADER CDib::GetDibInfoHeaderPtr()
{
	return m_pBmInfoHeader;
}


UINT CDib::GetDibHeight()
{
	return (UINT)m_pBmInfoHeader->biWidth;
}


UINT CDib::GetDibWidth()
{
	return  (UINT)m_pBmInfoHeader->biWidth;
}


DWORD CDib::GetDibSizeImage()
{
	if (m_pBmInfoHeader->biSizeImage == 0)
	{
		/*�����ֽ����������*/
		DWORD byteWidth =(DWORD)GetDibWidth();

		/*�߶�*/
		DWORD height = (DWORD)GetDibHeight();
		DWORD imageSize = byteWidth*height;
		return imageSize;
	}
	else return m_pBmInfoHeader->biSizeImage;
}






void CDib::LoadBitmapFile(const CString fileName)
{
	/*��λͼ�ļ�*/
	CFile file(fileName, CFile::modeRead);

	/*��λͼͷ�ļ������ڴ�*/
	BITMAPFILEHEADER bmFileHeader;
	file.Read((void*)&bmFileHeader, sizeof(bmFileHeader));

	/*����Ƿ�Ϊλͼ*/
	if (bmFileHeader.bfType != 0x4d42)
	{
		AfxMessageBox(_T("Not a bitmap file!"));
		m_pBmFileHeader = 0;
		m_pBmInfo = 0;
		m_pBmInfoHeader = 0;
		m_pRGBTable = 0;
		m_pDibBits = 0;
		m_numColors = 0;
	}
	else
	{
		DWORD fileLength = file.GetLength();
		DWORD dibSize = fileLength - sizeof(bmFileHeader);

		/*����ȫ���ڴ�*/
		BYTE* pDib = (BYTE*)GlobalAllocPtr(GMEM_MOVEABLE, dibSize);

		pDib = new BYTE(dibSize);
		file.Read(pDib, dibSize);
		file.Close();

		/*��ʼ��ָ��ṹBITMAPINFO��BITMAPINFOHEADER��ָ��*/
		m_pBmInfo = (LPBITMAPINFO)pDib;
		m_pBmInfoHeader = (LPBITMAPINFOHEADER)pDib;

		/*���λͼ��С*/
		m_pBmInfoHeader->biSizeImage = GetDibSizeImage();
		m_pDibBits = pDib + m_pBmInfoHeader->biSize;

	}
}
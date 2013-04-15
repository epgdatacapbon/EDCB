#ifndef __DESCRIPTOR_DEF_H__
#define __DESCRIPTOR_DEF_H__

#include "CADesc.h"
#include "AudioComponentDesc.h"
#include "AVCTimingHRDDesc.h"
#include "AVCVideoDesc.h"
#include "BoardInfoDesc.h"
#include "BouquetNameDesc.h"
#include "BroadcasterNameDesc.h"
#include "CAIdentifierDesc.h"
#include "ComponentDesc.h"
#include "ComponentGroupDesc.h"
#include "ConnectedTransmissionDesc.h"
#include "ContentAvailabilityDesc.h"
#include "ContentDesc.h"
#include "CountryAvailabilityDesc.h"
#include "DataComponentDesc.h"
#include "DataContentDesc.h"
#include "DigitalCopyCtrlDesc.h"
#include "EmergencyInfoDesc.h"
#include "EventGroupDesc.h"
#include "ExtendedBroadcasterDesc.h"
#include "ExtendedEventDesc.h"
#include "HierarchicalTransmissionDesc.h"
#include "HyperlinkDesc.h"
#include "LDTLinkageDesc.h"
#include "LinkageDesc.h"
#include "LocalTimeOffsetDesc.h"
#include "LogoTransmissionDesc.h"
#include "MosaicDesc.h"
#include "NetworkNameDesc.h"
#include "NVODReferenceDesc.h"
#include "ParentalRatingDesc.h"
#include "PartialReceptionDesc.h"
#include "SatelliteDeliverySysDesc.h"
#include "SeriesDesc.h"
#include "ServiceDesc.h"
#include "ServiceGroupDesc.h"
#include "ServiceListDesc.h"
#include "ShortEventDesc.h"
#include "SIParameterDesc.h"
#include "SIPrime_tsDesc.h"
#include "StreamIdentifierDesc.h"
#include "StuffingDesc.h"
#include "SystemManagementDesc.h"
#include "TargetRegionDesc.h"
#include "TerrestrialDeliverySysDesc.h"
#include "TimeShiftedEventDesc.h"
#include "TimeShiftedServiceDesc.h"
#include "TSInfoDesc.h"
#include "VideoDecodeCtrlDesc.h"
#include "PartialTransportStreamDesc.h"
#include "NetworkIdentification.h"
#include "PartialTSTimeDesc.h"
#include "DownloadContentDesc.h"

typedef struct _DESCRIPTOR_DATA{
	CCADesc* CA;
	CAudioComponentDesc* audioComponent;
	CAVCTimingHRDDesc*	AVCTimingHRD;
	CAVCVideoDesc* AVCVideo;
	CBoardInfoDesc* boardInfo;
	CBouquetNameDesc* bouquetName;
	CBroadcasterNameDesc* broadcasterName;
	CCAIdentifierDesc* CAIdentifier;
	CComponentDesc* component;
	CComponentGroupDesc* componentGroup;
	CConnectedTransmissionDesc* connectedTransmission;
	CContentAvailabilityDesc* contentAvailability;
	CContentDesc* content;
	CCountryAvailabilityDesc* countryAvailability;
	CDataComponentDesc* dataComponent;
	CDataContentDesc* dataContent;
	CDigitalCopyCtrlDesc* digitalCopyCtrl;
	CEmergencyInfoDesc* emergencyInfo;
	CEventGroupDesc* eventGroup;
	CExtendedBroadcasterDesc* extendedBroadcaster;
	CExtendedEventDesc* extendedEvent;
	CHierarchicalTransmissionDesc* hierarchicalTransmission;
	CHyperlinkDesc* hyperlink;
	CLDTLinkageDesc* LDTLinkage;
	CLinkageDesc* linkage;
	CLocalTimeOffsetDesc* localTimeOffset;
	CLogoTransmissionDesc* logoTransmission;
	CMosaicDesc* mosaic;
	CNetworkNameDesc* networkName;
	CNVODReferenceDesc* NVODReference;
	CParentalRatingDesc* parentalRating;
	CPartialReceptionDesc* partialReception;
	CSatelliteDeliverySysDesc* satelliteDeliverySys;
	CSeriesDesc* series;
	CServiceDesc* service;
	CServiceGroupDesc* serviceGroup;
	CServiceListDesc* serviceList;
	CShortEventDesc* shortEvent;
	CSIParameterDesc* SIParameter;
	CSIPrime_tsDesc* SIPrime_ts;
	CStreamIdentifierDesc* streamIdentifier;
	CStuffingDesc* stuffing;
	CSystemManagementDesc* systemManagement;
	CTargetRegionDesc* targetRegion;
	CTerrestrialDeliverySysDesc* terrestrialDeliverySys;
	CTimeShiftedEventDesc* timeShiftedEvent;
	CTimeShiftedServiceDesc* timeShiftedService;
	CTSInfoDesc* TSInfo;
	CVideoDecodeCtrlDesc* videoDecodeCtrl;
	CPartialTransportStreamDesc* partialTransportStream;
	CNetworkIdentification* networkIdentification;
	CPartialTSTimeDesc* partialTSTime;
	CDownloadContentDesc* downloadContent;

	_DESCRIPTOR_DATA(void){
		CA = NULL;
		audioComponent = NULL;
		AVCTimingHRD = NULL;
		AVCVideo = NULL;
		boardInfo = NULL;
		bouquetName = NULL;
		broadcasterName = NULL;
		CAIdentifier = NULL;
		component = NULL;
		componentGroup = NULL;
		connectedTransmission = NULL;
		contentAvailability = NULL;
		content = NULL;
		countryAvailability = NULL;
		dataComponent = NULL;
		dataContent = NULL;
		digitalCopyCtrl = NULL;
		emergencyInfo = NULL;
		eventGroup = NULL;
		extendedBroadcaster = NULL;
		extendedEvent = NULL;
		hierarchicalTransmission = NULL;
		hyperlink = NULL;
		LDTLinkage = NULL;
		linkage = NULL;
		localTimeOffset = NULL;
		logoTransmission = NULL;
		mosaic = NULL;
		networkName = NULL;
		NVODReference = NULL;
		parentalRating = NULL;
		partialReception = NULL;
		satelliteDeliverySys = NULL;
		series = NULL;
		service = NULL;
		serviceGroup = NULL;
		serviceList = NULL;
		shortEvent = NULL;
		SIParameter = NULL;
		SIPrime_ts = NULL;
		streamIdentifier = NULL;
		stuffing = NULL;
		systemManagement = NULL;
		targetRegion = NULL;
		terrestrialDeliverySys = NULL;
		timeShiftedEvent = NULL;
		timeShiftedService = NULL;
		TSInfo = NULL;
		videoDecodeCtrl = NULL;
		partialTransportStream = NULL;
		networkIdentification = NULL;
		partialTSTime = NULL;
		downloadContent = NULL;
	};
	~_DESCRIPTOR_DATA(void){
		SAFE_DELETE(CA);
		SAFE_DELETE(audioComponent);
		SAFE_DELETE(AVCTimingHRD);
		SAFE_DELETE(AVCVideo);
		SAFE_DELETE(boardInfo);
		SAFE_DELETE(bouquetName);
		SAFE_DELETE(broadcasterName);
		SAFE_DELETE(CAIdentifier);
		SAFE_DELETE(component);
		SAFE_DELETE(componentGroup);
		SAFE_DELETE(connectedTransmission);
		SAFE_DELETE(contentAvailability);
		SAFE_DELETE(content);
		SAFE_DELETE(countryAvailability);
		SAFE_DELETE(dataComponent);
		SAFE_DELETE(dataContent);
		SAFE_DELETE(digitalCopyCtrl);
		SAFE_DELETE(emergencyInfo);
		SAFE_DELETE(eventGroup);
		SAFE_DELETE(extendedBroadcaster);
		SAFE_DELETE(extendedEvent);
		SAFE_DELETE(hierarchicalTransmission);
		SAFE_DELETE(hyperlink);
		SAFE_DELETE(LDTLinkage);
		SAFE_DELETE(linkage);
		SAFE_DELETE(localTimeOffset);
		SAFE_DELETE(logoTransmission);
		SAFE_DELETE(mosaic);
		SAFE_DELETE(networkName);
		SAFE_DELETE(NVODReference);
		SAFE_DELETE(parentalRating);
		SAFE_DELETE(partialReception);
		SAFE_DELETE(satelliteDeliverySys);
		SAFE_DELETE(series);
		SAFE_DELETE(service);
		SAFE_DELETE(serviceGroup);
		SAFE_DELETE(serviceList);
		SAFE_DELETE(shortEvent);
		SAFE_DELETE(SIParameter);
		SAFE_DELETE(SIPrime_ts);
		SAFE_DELETE(streamIdentifier);
		SAFE_DELETE(stuffing);
		SAFE_DELETE(systemManagement);
		SAFE_DELETE(targetRegion);
		SAFE_DELETE(terrestrialDeliverySys);
		SAFE_DELETE(timeShiftedEvent);
		SAFE_DELETE(timeShiftedService);
		SAFE_DELETE(TSInfo);
		SAFE_DELETE(videoDecodeCtrl);
		SAFE_DELETE(partialTransportStream);
		SAFE_DELETE(networkIdentification);
		SAFE_DELETE(partialTSTime);
		SAFE_DELETE(downloadContent);
	};
}DESCRIPTOR_DATA;

//////////////////////////////////////////////////////
//�����M�������ʂ̊�����
typedef struct _CA_SYSTEM_TABLE{
	WORD CA_system_id;
	wstring name;
} CA_SYSTEM_TABLE;

static CA_SYSTEM_TABLE CASystemIDTable[]={
	{ 0x0001, L"�X�J�p�[�����M����" },
	{ 0x0003, L"��������" },
	{ 0x0004, L"Secure Navi����" },
	{ 0x0005, L"ARIB�����M����" },
	{ 0x0006, L"����CATV�����M����" },
	{ 0x0007, L"�P�[�u�����{�����������" },
	{ 0x0008, L"u-CAS����" },
	{ 0x0009, L"PowerKEY����" },
	{ 0x000A, L"ARIB�����MB����" },
	{ 0x000B, L"�p�C�V�X�����M����" },
	{ 0x000C, L"MULTI2-NAGRA����" },
	{ 0x000D, L"IPTV�t�H�[�����EMarlin����" }
};
//->�����M�������ʂ̊�����

//////////////////////////////////////////////////////
//�R���|�[�l���g���e�ƃR���|�[�l���g���
typedef struct _COMPONENT_TYPE_TABLE{
	BYTE stream_content;
	BYTE component_type;
	wstring name;
} COMPONENT_TYPE_TABLE;

static COMPONENT_TYPE_TABLE componentTypeTable[]={
	{ 0x01, 0x01, L"�f��480i(525i)�A�A�X�y�N�g��4:3" },
	{ 0x01, 0x02, L"�f��480i(525i)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x01, 0x03, L"�f��480i(525i)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x01, 0x04, L"�f��480i(525i)�A�A�X�y�N�g�� > 16:9" },
	{ 0x01, 0x91, L"�f��2160p�A�A�X�y�N�g��4:3" },
	{ 0x01, 0x92, L"�f��2160p�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x01, 0x93, L"�f��2160p�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x01, 0x94, L"�f��2160p�A�A�X�y�N�g�� > 16:9" },
	{ 0x01, 0xA1, L"�f��480p(525p)�A�A�X�y�N�g��4:3" },
	{ 0x01, 0xA2, L"�f��480p(525p)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x01, 0xA3, L"�f��480p(525p)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x01, 0xA4, L"�f��480p(525p)�A�A�X�y�N�g�� > 16:9" },
	{ 0x01, 0xB1, L"�f��1080i(1125i)�A�A�X�y�N�g��4:3" },
	{ 0x01, 0xB2, L"�f��1080i(1125i)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x01, 0xB3, L"�f��1080i(1125i)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x01, 0xB4, L"�f��1080i(1125i)�A�A�X�y�N�g�� > 16:9" },
	{ 0x01, 0xC1, L"�f��720p(750p)�A�A�X�y�N�g��4:3" },
	{ 0x01, 0xC2, L"�f��720p(750p)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x01, 0xC3, L"�f��720p(750p)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x01, 0xC4, L"�f��720p(750p)�A�A�X�y�N�g�� > 16:9" },
	{ 0x01, 0xD1, L"�f��240p �A�X�y�N�g��4:3" },
	{ 0x01, 0xD2, L"�f��240p �A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x01, 0xD3, L"�f��240p �A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x01, 0xD4, L"�f��240p �A�X�y�N�g�� > 16:9" },
	{ 0x01, 0xE1, L"�f��1080p(1125p)�A�A�X�y�N�g��4:3" },
	{ 0x01, 0xE2, L"�f��1080p(1125p)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x01, 0xE3, L"�f��1080p(1125p)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x01, 0xE4, L"�f��1080p(1125p)�A�A�X�y�N�g�� > 16:9" },
	{ 0x02, 0x01, L"�����A1/0���[�h�i�V���O�����m�j" },
	{ 0x02, 0x02, L"�����A1/0�{1/0���[�h�i�f���A�����m�j" },
	{ 0x02, 0x03, L"�����A2/0���[�h�i�X�e���I�j" },
	{ 0x02, 0x04, L"�����A2/1���[�h" },
	{ 0x02, 0x05, L"�����A3/0���[�h" },
	{ 0x02, 0x06, L"�����A2/2���[�h" },
	{ 0x02, 0x07, L"�����A3/1���[�h" },
	{ 0x02, 0x08, L"�����A3/2���[�h" },
	{ 0x02, 0x09, L"�����A3/2�{LFE���[�h�i3/2.1���[�h�j" },
	{ 0x02, 0x0A, L"�����A3/3.1���[�h" },
	{ 0x02, 0x0B, L"�����A2/0/0-2/0/2-0.1���[�h" },
	{ 0x02, 0x0C, L"�����A5/2.1���[�h" },
	{ 0x02, 0x0D, L"�����A3/2/2.1���[�h" },
	{ 0x02, 0x0E, L"�����A2/0/0-3/0/2-0.1���[�h" },
	{ 0x02, 0x0F, L"�����A0/2/0-3/0/2-0.1���[�h" },
	{ 0x02, 0x10, L"�����A2/0/0-3/2/3-0.2���[�h" },
	{ 0x02, 0x11, L"�����A3/3/3-5/2/3-3/0/0.2���[�h" },
	{ 0x02, 0x40, L"���o��Q�җp�������" },
	{ 0x02, 0x41, L"���o��Q�җp����" },
	{ 0x05, 0x01, L"H.264|MPEG-4 AVC�A�f��480i(525i)�A�A�X�y�N�g��4:3" },
	{ 0x05, 0x02, L"H.264|MPEG-4 AVC�A�f��480i(525i)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x05, 0x03, L"H.264|MPEG-4 AVC�A�f��480i(525i)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x05, 0x04, L"H.264|MPEG-4 AVC�A�f��480i(525i)�A�A�X�y�N�g�� > 16:9" },
	{ 0x05, 0x91, L"H.264|MPEG-4 AVC�A�f��2160p�A�A�X�y�N�g��4:3" },
	{ 0x05, 0x92, L"H.264|MPEG-4 AVC�A�f��2160p�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x05, 0x93, L"H.264|MPEG-4 AVC�A�f��2160p�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x05, 0x94, L"H.264|MPEG-4 AVC�A�f��2160p�A�A�X�y�N�g�� > 16:9" },
	{ 0x05, 0xA1, L"H.264|MPEG-4 AVC�A�f��480p(525p)�A�A�X�y�N�g��4:3" },
	{ 0x05, 0xA2, L"H.264|MPEG-4 AVC�A�f��480p(525p)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x05, 0xA3, L"H.264|MPEG-4 AVC�A�f��480p(525p)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x05, 0xA4, L"H.264|MPEG-4 AVC�A�f��480p(525p)�A�A�X�y�N�g�� > 16:9" },
	{ 0x05, 0xB1, L"H.264|MPEG-4 AVC�A�f��1080i(1125i)�A�A�X�y�N�g��4:3" },
	{ 0x05, 0xB2, L"H.264|MPEG-4 AVC�A�f��1080i(1125i)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x05, 0xB3, L"H.264|MPEG-4 AVC�A�f��1080i(1125i)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x05, 0xB4, L"H.264|MPEG-4 AVC�A�f��1080i(1125i)�A�A�X�y�N�g�� > 16:9" },
	{ 0x05, 0xC1, L"H.264|MPEG-4 AVC�A�f��720p(750p)�A�A�X�y�N�g��4:3" },
	{ 0x05, 0xC2, L"H.264|MPEG-4 AVC�A�f��720p(750p)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x05, 0xC3, L"H.264|MPEG-4 AVC�A�f��720p(750p)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x05, 0xC4, L"H.264|MPEG-4 AVC�A�f��720p(750p)�A�A�X�y�N�g�� > 16:9" },
	{ 0x05, 0xD1, L"H.264|MPEG-4 AVC�A�f��240p �A�X�y�N�g��4:3" },
	{ 0x05, 0xD2, L"H.264|MPEG-4 AVC�A�f��240p �A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x05, 0xD3, L"H.264|MPEG-4 AVC�A�f��240p �A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x05, 0xD4, L"H.264|MPEG-4 AVC�A�f��240p �A�X�y�N�g�� > 16:9" },
	{ 0x05, 0xE1, L"H.264|MPEG-4 AVC�A�f��1080p(1125p)�A�A�X�y�N�g��4:3" },
	{ 0x05, 0xE2, L"H.264|MPEG-4 AVC�A�f��1080p(1125p)�A�A�X�y�N�g��16:9 �p���x�N�g������" },
	{ 0x05, 0xE3, L"H.264|MPEG-4 AVC�A�f��1080p(1125p)�A�A�X�y�N�g��16:9 �p���x�N�g���Ȃ�" },
	{ 0x05, 0xE4, L"H.264|MPEG-4 AVC�A�f��1080p(1125p)�A�A�X�y�N�g�� > 16:9" }
};
//->�R���|�[�l���g���e�ƃR���|�[�l���g���

//////////////////////////////////////////////////////
//�R���e���g�L�q�q�ɂ�����W�������w��
typedef struct _NIBBLE_TABLE_1{
	BYTE content_nibble_level_1;
	wstring name;
} NIBBLE_TABLE_1;

static NIBBLE_TABLE_1 nibbleTable1[]={
	{ 0x00, L"�j���[�X�^��" },
	{ 0x01, L"�X�|�[�c" },
	{ 0x02, L"���^���C�h�V���[" },
	{ 0x03, L"�h���}" },
	{ 0x04, L"���y" },
	{ 0x05, L"�o���G�e�B" },
	{ 0x06, L"�f��" },
	{ 0x07, L"�A�j���^���B" },
	{ 0x08, L"�h�L�������^���[�^���{" },
	{ 0x09, L"����^����" },
	{ 0x0A, L"��^����" },
	{ 0x0B, L"����" },
	{ 0x0E, L"�g��" },
	{ 0x0F, L"���̑�" },
};

typedef struct _NIBBLE_TABLE_2{
	BYTE content_nibble_level_1;
	BYTE content_nibble_level_2;
	wstring name;
} NIBBLE_TABLE_2;

static NIBBLE_TABLE_2 nibbleTable2[]={
	{ 0x00, 0x00, L"�莞�E����" },
	{ 0x00, 0x01, L"�V�C" },
	{ 0x00, 0x02, L"���W�E�h�L�������g" },
	{ 0x00, 0x03, L"�����E����" },
	{ 0x00, 0x04, L"�o�ρE�s��" },
	{ 0x00, 0x05, L"�C�O�E����" },
	{ 0x00, 0x06, L"���" },
	{ 0x00, 0x07, L"���_�E��k" },
	{ 0x00, 0x08, L"�񓹓���" },
	{ 0x00, 0x09, L"���[�J���E�n��" },
	{ 0x00, 0x0A, L"���" },
	{ 0x00, 0x0F, L"���̑�" },
	{ 0x01, 0x00, L"�X�|�[�c�j���[�X" },
	{ 0x01, 0x01, L"�싅" },
	{ 0x01, 0x02, L"�T�b�J�[" },
	{ 0x01, 0x03, L"�S���t" },
	{ 0x01, 0x04, L"���̑��̋��Z" },
	{ 0x01, 0x05, L"���o�E�i���Z" },
	{ 0x01, 0x06, L"�I�����s�b�N�E���ۑ��" },
	{ 0x01, 0x07, L"�}���\���E����E���j" },
	{ 0x01, 0x08, L"���[�^�[�X�|�[�c" },
	{ 0x01, 0x09, L"�}�����E�E�B���^�[�X�|�[�c" },
	{ 0x01, 0x0A, L"���n�E���c���Z" },
	{ 0x01, 0x0F, L"���̑�" },
	{ 0x02, 0x00, L"�|�\�E���C�h�V���[" },
	{ 0x02, 0x01, L"�t�@�b�V����" },
	{ 0x02, 0x02, L"��炵�E�Z�܂�" },
	{ 0x02, 0x03, L"���N�E���" },
	{ 0x02, 0x04, L"�V���b�s���O�E�ʔ�" },
	{ 0x02, 0x05, L"�O�����E����" },
	{ 0x02, 0x06, L"�C�x���g" },
	{ 0x02, 0x07, L"�ԑg�Љ�E���m�点" },
	{ 0x02, 0x0F, L"���̑�" },
	{ 0x03, 0x00, L"�����h���}" },
	{ 0x03, 0x01, L"�C�O�h���}" },
	{ 0x03, 0x02, L"���㌀" },
	{ 0x03, 0x0F, L"���̑�" },
	{ 0x04, 0x00, L"�������b�N�E�|�b�v�X" },
	{ 0x04, 0x01, L"�C�O���b�N�E�|�b�v�X" },
	{ 0x04, 0x02, L"�N���V�b�N�E�I�y��" },
	{ 0x04, 0x03, L"�W���Y�E�t���[�W����" },
	{ 0x04, 0x04, L"�̗w�ȁE����" },
	{ 0x04, 0x05, L"���C�u�E�R���T�[�g" },
	{ 0x04, 0x06, L"�����L���O�E���N�G�X�g" },
	{ 0x04, 0x07, L"�J���I�P�E�̂ǎ���" },
	{ 0x04, 0x08, L"���w�E�M�y" },
	{ 0x04, 0x09, L"���w�E�L�b�Y" },
	{ 0x04, 0x0A, L"�������y�E���[���h�~���[�W�b�N" },
	{ 0x04, 0x0F, L"���̑�" },
	{ 0x05, 0x00, L"�N�C�Y" },
	{ 0x05, 0x01, L"�Q�[��" },
	{ 0x05, 0x02, L"�g�[�N�o���G�e�B" },
	{ 0x05, 0x03, L"���΂��E�R���f�B" },
	{ 0x05, 0x04, L"���y�o���G�e�B" },
	{ 0x05, 0x05, L"���o���G�e�B" },
	{ 0x05, 0x06, L"�����o���G�e�B" },
	{ 0x05, 0x0F, L"���̑�" },
	{ 0x06, 0x00, L"�m��" },
	{ 0x06, 0x01, L"�M��" },
	{ 0x06, 0x02, L"�A�j��" },
	{ 0x06, 0x0F, L"���̑�" },
	{ 0x07, 0x00, L"�����A�j��" },
	{ 0x07, 0x01, L"�C�O�A�j��" },
	{ 0x07, 0x02, L"���B" },
	{ 0x07, 0x0F, L"���̑�" },
	{ 0x08, 0x00, L"�Љ�E����" },
	{ 0x08, 0x01, L"���j�E�I�s" },
	{ 0x08, 0x02, L"���R�E�����E��" },
	{ 0x08, 0x03, L"�F���E�Ȋw�E��w" },
	{ 0x08, 0x04, L"�J���`���[�E�`������" },
	{ 0x08, 0x05, L"���w�E���|" },
	{ 0x08, 0x06, L"�X�|�[�c" },
	{ 0x08, 0x07, L"�h�L�������^���[�S��" },
	{ 0x08, 0x08, L"�C���^�r���[�E���_" },
	{ 0x08, 0x0F, L"���̑�" },
	{ 0x09, 0x00, L"���㌀�E�V��" },
	{ 0x09, 0x01, L"�~���[�W�J��" },
	{ 0x09, 0x02, L"�_���X�E�o���G" },
	{ 0x09, 0x03, L"����E���|" },
	{ 0x09, 0x04, L"�̕���E�ÓT" },
	{ 0x09, 0x0F, L"���̑�" },
	{ 0x0A, 0x00, L"���E�ނ�E�A�E�g�h�A" },
	{ 0x0A, 0x01, L"���|�E�y�b�g�E��|" },
	{ 0x0A, 0x02, L"���y�E���p�E�H�|" },
	{ 0x0A, 0x03, L"�͌�E����" },
	{ 0x0A, 0x04, L"�����E�p�`���R" },
	{ 0x0A, 0x05, L"�ԁE�I�[�g�o�C" },
	{ 0x0A, 0x06, L"�R���s���[�^�E�s�u�Q�[��" },
	{ 0x0A, 0x07, L"��b�E��w" },
	{ 0x0A, 0x08, L"�c���E���w��" },
	{ 0x0A, 0x09, L"���w���E���Z��" },
	{ 0x0A, 0x0A, L"��w���E��" },
	{ 0x0A, 0x0B, L"���U����E���i" },
	{ 0x0A, 0x0C, L"������" },
	{ 0x0A, 0x0F, L"���̑�" },
	{ 0x0B, 0x00, L"�����" },
	{ 0x0B, 0x01, L"��Q��" },
	{ 0x0B, 0x02, L"�Љ��" },
	{ 0x0B, 0x03, L"�{�����e�B�A" },
	{ 0x0B, 0x04, L"��b" },
	{ 0x0B, 0x05, L"�����i�����j" },
	{ 0x0B, 0x06, L"�������" },
	{ 0x0E, 0x0F, L"���̑�" },
	{ 0x0E, 0x00, L"BS/�n��f�W�^�������p�ԑg�t�����" },
	{ 0x0E, 0x01, L"�L�ш�CS �f�W�^�������p�g��" },
	{ 0x0E, 0x02, L"�q���f�W�^�����������p�g��" },
	{ 0x0E, 0x03, L"�T�[�o�[�^�ԑg�t�����" },
	{ 0x0E, 0x04, L"IP �����p�ԑg�t�����" }
};
//->�R���e���g�L�q�q�ɂ�����W�������w��

//////////////////////////////////////////////////////
//�T�[�r�X�`�����
typedef struct _SERVICE_TYPE_TABLE{
	BYTE service_type;
	wstring name;
} SERVICE_TYPE_TABLE;

static SERVICE_TYPE_TABLE serviceTypeTable[]={
	{ 0x01, L"�f�W�^���s�u�T�[�r�X" },
	{ 0x02, L"�f�W�^�������T�[�r�X" },
	{ 0xA1, L"�Վ��f���T�[�r�X" },
	{ 0xA2, L"�Վ������T�[�r�X" },
	{ 0xA3, L"�Վ��f�[�^�T�[�r�X" },
	{ 0xA4, L"�G���W�j�A�����O�T�[�r�X" },
	{ 0xA5, L"�v�����[�V�����f���T�[�r�X" },
	{ 0xA6, L"�v�����[�V���������T�[�r�X" },
	{ 0xA7, L"�v�����[�V�����f�[�^�T�[�r�X" },
	{ 0xA8, L"���O�~�ϗp�f�[�^�T�[�r�X" },
	{ 0xA9, L"�~�ϐ�p�f�[�^�T�[�r�X" },
	{ 0xAA, L"�u�b�N�}�[�N�ꗗ�f�[�^�T�[�r�X" },
	{ 0xAB, L"�T�[�o�[�^�T�C�}���T�[�r�X" },
	{ 0xAC, L"�Ɨ��t�@�C���T�[�r�X" },
	{ 0xC0, L"�f�[�^�T�[�r�X" },
	{ 0xC1, L"TLV��p�����~�ό^�T�[�r�X" }
};

//->�T�[�r�X�`�����
#endif

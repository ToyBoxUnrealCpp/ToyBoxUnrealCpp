// Fill out your copyright notice in the Description page of Project Settings.
// Auther is You O to publish my blog

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "meaninglessObject.h"
#include "uPropertyList.generated.h"

// Multicast Delegate Type
// �K�v����������
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FmeaninglessDelegate);

// This class was created only that explain UPROPERTY macro
UCLASS()
class TOYBOXUNREALCPPTPS_API AuPropertyList : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AuPropertyList();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// EditAnywhere:	You can modify this property from Level Editor's Details Panel and Blueprint Editor's Details Panel.
	UPROPERTY(EditAnywhere, Category = "Edit")
	// EditAnywhere�ŁA���x���G�f�B�^�ƃu���[�v�����g�G�f�B�^���炱�̕ϐ���ύX���邱�Ƃ��ł��܂��B
	int32 m_editAnywhere;

	// EditDefaultsOnly:	You can modify this property from Blueprint Editor's Details Panel only
	UPROPERTY(EditDefaultsOnly, Category = "Edit")
	// EditDefaultsOnly�ŁA�u���[�v�����g�G�f�B�^���炱�̕ϐ���ύX���邱�Ƃ��ł��܂��B
	// �������A���x���G�f�B�^����̕ύX�͋֎~���܂��B
	int32 m_editDefaultsOnly;

	// EditInstanceOnly:	You can modify this property from Level Editor's Details Panel only
	UPROPERTY(EditInstanceOnly, Category = "Edit")
	// EditInstanceOnly�ŁA���x���G�f�B�^���炱�̕ϐ���ύX���邱�Ƃ��ł��܂��B
	// �������A�u���[�v�����g�G�f�B�^����̕ύX�͋֎~���܂��B
	int32 m_editInstanceOnly;

	// VisibleAnywhere:	You can not modify this property.
	//					But you can view this property from Level Editor's Details Panel and Blueprint Editor's Details Panel.
	UPROPERTY(VisibleAnywhere, Category = "Visible")
	// VisibleAnywhere�ŁA���x���G�f�B�^�ƃu���[�v�����g�G�f�B�^���炱�̕ϐ����m�F�ł��܂��B
	// �������A�ύX�͂ł��܂���B
	int32 m_visibleAnywhere;

	// VisibleDefaultsOnly:	You can not modify this property.
	//						But you can watch this property from Blueprint Editor's Details Panel only.
	UPROPERTY(VisibleDefaultsOnly, Category = "Visible")
	// VisibleDefaultsOnly�ŁA�u���[�v�����g�G�f�B�^���炱�̕ϐ����m�F�ł��܂��B
	// �������A���x���u���[�v�����g����m�F���邱�Ƃ͂ł��܂���B
	int32 m_visibleDefaulesOnly;

	// VisibleInstanceOnly:	You can not modify this property.
	//						But you can watch this property from Level Editor's Details Panel only.
	UPROPERTY(VisibleInstanceOnly, Category = "Visible")
	// VisibleInstanceOnly�ŁA���x���G�f�B�^���炱�̕ϐ����m�F�ł��܂��B
	// �������A�u���[�v�����g�G�f�B�^����m�F���邱�Ƃ͂ł��܂���B
	int32 m_visibleInstanceOnly;

	// Category:	Specifies the category of the property.
	UPROPERTY(VisibleAnywhere, Category = "This is Main Category")
	// Category�ŕϐ��̃J�e�S��������ł��܂��B
	int32 m_category;
	//				Define nested categories using the | operator.
	UPROPERTY(VisibleAnywhere, Category = "This is Main Category|This is Sub Category")
	// |�ŋ�؂邱�Ƃɂ���āA�T�u�J�e�S��������ł��܂��B
	int32 m_subCategory;

	// SimpleDisplay:	This property appear visible by default in the Details panel.
	UPROPERTY(SimpleDisplay, VisibleAnywhere, Category = "Display Type")
	// SimpleDisplay�Ńf�B�e�[���p�l���̃f�t�H���g�ʒu�ɕ\���ł��܂��B
	int32 m_simpleDisplay;

	// AdvancedDisplay:	Properties are in the advanced dropdown in a Details panel.
	UPROPERTY(AdvancedDisplay, VisibleAnywhere, Category = "Display Type")
	// AdvancedDisplay�Ńh���b�v�_�E�����X�g�Ƃ��ĉB�����Ƃ��\�ł��B
	int32 m_advancedDisplay;

	// BlueprintReadOnly:	This property can be read by Blueprints, but not modified. 
	//						This operator is incompatible with the BlueprintReadWrite specifier.
	UPROPERTY(BlueprintReadOnly)
	// BlueprintReadOnly�ŁA�u���[�v�����g�œǂݍ��߂�悤�ɂȂ�܂��B
	// �������A�ύX�͂ł��܂���B
	// BlueprintReadWrite�Ƃ͓����Ɏg���܂���B
	int32 m_blueprintReadOnly;

	// BlueprintReadWrite:	This property can be read or written from a Blueprint.
	//						This operator is incompatible with the BlueprintReadOnly specifier.
	UPROPERTY(BlueprintReadWrite)
	// BlueprintReadWrite�ŁA�u���[�v�����g�œǂݍ��񂾂�ύX������ł���悤�ɂȂ�܂��B
	// BlueprintReadOnly�Ƃ͓����Ɏg���܂���B
	int32 m_blueprintReadWrite;

	// Compare with m_editFixedSize
	UPROPERTY(EditAnywhere, Category = "Array|Variable Length")
	// EditFixedSize�Ɣ�r����p�ɍ����
	TArray<int32> m_array = { 1, 2, 3 };

	// EditFixedSize:	Only useful for dynamic arrays.
	//					This will prevent the user from changing the length of an array via the Unreal Editor property window.
	UPROPERTY(EditFixedSize, EditAnywhere, Category = "Array|Fixed Size")
	// EditFixedSize�͉ϒ��z��ɂ����g���܂���B
	// �ϒ��z��̒������G�f�B�^����ύX�ł��Ȃ��悤�ɂ��܂��B
	TArray<int32> m_editFixedSize = { 1, 2, 3 };

	// BlueprintAssignable:	This specifier can use with Multicast Delegates only.
	//						Exposes the property for assigning in Blueprints.
	UPROPERTY(BlueprintAssignable, Category = "Delegate|Bind")
	// ���̎w��q�̓}���`�L���X�g�f���Q�[�g�^�ł����g���܂���B
	// BlueptrintAssignable�ŁA���̕ϐ����u���[�v�����g�Ƀo�C���h�\�ȃf���Q�[�g�Ƃ��Č��J���邱�Ƃ��ł��܂��B
	FmeaninglessDelegate m_blueprintAssignable;

	// BlueprintCallable:	This specifier can use with Multicast Delegates only.
	//						This property should be exposed for calling in Blueprint code.
	UPROPERTY(BlueprintCallable, Category = "Delegate|Call")
	// ���̎w��q�̓}���`�L���X�g�f���Q�[�g�^�ł����g���܂���B
	// BlueptrintCallable�ŁA���̕ϐ����u���[�v�����g�ŃR�[���\�ȃf���Q�[�g�Ƃ��Č��J���邱�Ƃ��ł��܂��B
	FmeaninglessDelegate m_blueprintCallable;

	// This delegate accepts(only in blueprint) only events with BlueprintAuthorityOnly.
	UPROPERTY(BlueprintAuthorityOnly, BlueprintReadWrite)
	// BlueprintAuthorityOnly�̃C�x���g�̂ݎ󂯕t���܂��B
	FmeaninglessDelegate m_blueprintAuthorityOnly;

	// Object properties only. 
	// When an instance of this class is created, it will be given a unique copy of the object assigned to this variable in defaults.
	UPROPERTY(Instanced, EditAnywhere)
	// �I�u�W�F�N�g����
	// ���̃N���X�̃C���X�^���X���������ꂽ�Ƃ��A�C���X�^���X�ɂ͂��̕ϐ��ɐݒ肳��Ă���I�u�W�F�N�g�̃R�s�[�����������B
	class UStaticMeshComponent* m_instanced;

	// Property should be serialized for save game.
	UPROPERTY(SaveGame)
	// �Z�[�u���邽�߂ɂ��̕ϐ��̓V���A���C�Y����Ȃ���΂Ȃ�܂���B
	int32 m_SaveGame;

	// Transient:	Property is transient: shouldn't be saved, zero-filled at load time. Opposite of the SaveGame specifier.
	UPROPERTY(Transient, EditAnywhere, Category = "Transient|Transient")
	// Transient�ŃV���A���C�Y�s�ȕϐ��ɂ��邱�Ƃ��ł��܂��B
	// SaveGame�w��q�Ɠ����ɂ͈����܂���B
	int32 m_transient;

	// DuplicateTransient:	Property should always be reset to the default value during any type of duplication (copy/paste, binary duplication, etc.)
	UPROPERTY(DuplicateTransient, EditAnywhere, Category = "Transient|DuplicateTransient")
	// DuplicateTransient�w��q�ŁA������(�R�s�[/�y�[�X�g�Ƃ�)�̃V���A���C�Y���ł��Ȃ����܂��B
	int32 m_duplicateTransient;

	// Property should always be reset to the default value unless it's being duplicated for a PIE session.
	UPROPERTY(NonPIEDuplicateTransient, EditAnywhere, Category = "Transient|NonPIEDuplicateTransient")
	// PIE(Play in Editor)�Z�b�V�����p�ɕ������Ă��Ȃ��Ƃ��A�V���A���C�Y���֎~���܂��B
	int32 m_nonPIETransient;

	UPROPERTY(TextExportTransient, EditAnywhere, Category = "Transient|TextExportTransient")
		int32 m_textExportTransient;

	UPROPERTY(EditAnywhere, Category = "Clear|Can Clear")
	// NoClear�̔�r�p
	class USkeletalMesh* m_yesClear;
	
	// NoClear:	Prevents this object reference from being set to none from the editor.
	//			Hides clear(and browse) button in the editor.
	UPROPERTY(NoClear, EditAnywhere, Category = "Clear|Can not Clear")
	// NoClear�w��q��Clear�{�^����None�{�^�������G�f�B�^�ォ��铽���܂��B
	class USkeletalMesh* m_noClear;

	// Export:	Only useful for object properties (or arrays of objects). 
	//			Indicates that the object assigned to this property should be exported in its entirety as a subobject block when the object is copied (for copy/paste) or exported to T3D,
	//			as opposed to just outputting the object reference itself.
	UPROPERTY(Export)
	// �I�u�W�F�N�g�̂ݗL��
	// Export�Ŏw�肳�ꂽ�ϐ��́A�G�N�X�|�[�g����A�R�s�[/�y�[�X�g����T3D(UnrealEngine�Ǝ��̃e�L�X�g�`��)�ɕۑ������ꍇ�A
	// ���̃I�u�W�F�N�g��<���O��p�X�A�ϐ��l>�̑����<���̃I�u�W�F�N�g���\�������`�f�[�^��C���N���[�h�f�[�^>���e�L�X�g������܂��B
	UmeaninglessObject* m_export;

	// Config:	This property should be loaded/saved to ini file as permanent profile.
	UPROPERTY(Config = "DefaultGame")
	// Config�Ŏw�肳�ꂽ���̕ϐ��͎w���.ini�t�@�C���։i���I�Ȑ��l�Ƃ��ăZ�[�u�A���h���[�h����Ȃ���΂Ȃ�܂���B
	int32 m_config;

	// GlobalConfig:	This is same as Config.
	//					But this property load config from base class, not subclass.
	UPROPERTY(GlobalConfig)
	// Config�Ɠ����ł����A�K���x�[�X�N���X����ǂݍ��܂��悤�ɂȂ�܂��B
	// �T�u�N���X����͓ǂݍ��܂�܂���B
	int32 m_globalConfig;

	// AssetRegistrySearchable:	This property and it's value will be automatically added to the asset registry for any asset class instances containing this as a member variable.
	//							It is not legal to use on struct properties or parameters.
	UPROPERTY(AssetRegistrySearchable, EditAnywhere)
	// AssetRegistrySearchable�w��q�������TagsAndValues�Ƃ���TMap�Ɋi�[����܂��B
	// ���̒l��ҏW���邱�Ƃɂ���āA���̕ϐ����̂��^�O�Ƃ��Ă��������Ƃ��ł��܂��B
	int32 m_assetRegistrySearchable;
};

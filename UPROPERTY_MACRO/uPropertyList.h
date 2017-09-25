// Fill out your copyright notice in the Description page of Project Settings.
// Auther is You O to publish my blog

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "uPropertyList.generated.h"

// Multicast Delegate Type
// 必要だから作った
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

	void noProcessDelegate() {}

public:
	// EditAnywhere:	You can modify this property from Level Editor's Details Panel and Blueprint Editor's Details Panel.
	UPROPERTY(EditAnywhere, Category = "Edit")
	// EditAnywhereで、レベルエディタとブループリントエディタからこの変数を変更することができます。
	int32 m_editAnywhere;

	// EditDefaultsOnly:	You can modify this property from Blueprint Editor's Details Panel only
	UPROPERTY(EditDefaultsOnly, Category = "Edit")
	// EditDefaultsOnlyで、ブループリントエディタからこの変数を変更することができます。
	// ただし、レベルエディタからの変更は禁止します。
	int32 m_editDefaultsOnly;

	// EditInstanceOnly:	You can modify this property from Level Editor's Details Panel only
	UPROPERTY(EditInstanceOnly, Category = "Edit")
	// EditInstanceOnlyで、レベルエディタからこの変数を変更することができます。
	// ただし、ブループリントエディタからの変更は禁止します。
	int32 m_editInstanceOnly;

	// VisibleAnywhere:	You can not modify this property.
	//					But you can view this property from Level Editor's Details Panel and Blueprint Editor's Details Panel.
	UPROPERTY(VisibleAnywhere, Category = "Visible")
	// VisibleAnywhereで、レベルエディタとブループリントエディタからこの変数を確認できます。
	// ただし、変更はできません。
	int32 m_visibleAnywhere;

	// VisibleDefaultsOnly:	You can not modify this property.
	//						But you can watch this property from Blueprint Editor's Details Panel only.
	UPROPERTY(VisibleDefaultsOnly, Category = "Visible")
	// VisibleDefaultsOnlyで、ブループリントエディタからこの変数を確認できます。
	// ただし、レベルブループリントから確認することはできません。
	int32 m_visibleDefaulesOnly;

	// VisibleInstanceOnly:	You can not modify this property.
	//						But you can watch this property from Level Editor's Details Panel only.
	UPROPERTY(VisibleInstanceOnly, Category = "Visible")
	// VisibleInstanceOnlyで、レベルエディタからこの変数を確認できます。
	// ただし、ブループリントエディタから確認することはできません。
	int32 m_visibleInstanceOnly;

	// Category:	Specifies the category of the property.
	UPROPERTY(VisibleAnywhere, Category = "This is Main Category")
	// Categoryで変数のカテゴリを決定できます。
	int32 m_category;
	//				Define nested categories using the | operator.
	UPROPERTY(VisibleAnywhere, Category = "This is Main Category|This is Sub Category")
	// |で区切ることによって、サブカテゴリを決定できます。
	int32 m_subCategory;

	// SimpleDisplay:	This property appear visible by default in the Details panel.
	UPROPERTY(SimpleDisplay, VisibleAnywhere, Category = "Display Type")
	// SimpleDisplayでディテールパネルのデフォルト位置に表示できます。
	int32 m_simpleDisplay;

	// AdvancedDisplay:	Properties are in the advanced dropdown in a Details panel.
	UPROPERTY(AdvancedDisplay, VisibleAnywhere, Category = "Display Type")
	// AdvancedDisplayでドロップダウンリストとして隠すことが可能です。
	int32 m_advancedDisplay;

	// BlueprintReadOnly:	This property can be read by Blueprints, but not modified. 
	//						This operator is incompatible with the BlueprintReadWrite specifier.
	UPROPERTY(BlueprintReadOnly)
	// BlueprintReadOnlyで、ブループリントで読み込めるようになります。
	// ただし、変更はできません。
	// BlueprintReadWriteとは同時に使えません。
	int32 m_blueprintReadOnly;

	// BlueprintReadWrite:	This property can be read or written from a Blueprint.
	//						This operator is incompatible with the BlueprintReadOnly specifier.
	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly)
	// BlueprintReadWriteで、ブループリントで読み込んだり変更したりできるようになります。
	// BlueprintReadOnlyとは同時に使えません。
	int32 m_blueprintReadWrite;

	// Compare with m_editFixedSize
	UPROPERTY(EditAnywhere, Category = "Array|Variable Length")
	// EditFixedSizeと比較する用に作った
	TArray<int32> m_array = { 1, 2, 3 };

	// EditFixedSize:	Only useful for dynamic arrays.
	//					This will prevent the user from changing the length of an array via the Unreal Editor property window.
	UPROPERTY(EditFixedSize, EditAnywhere, Category = "Array|Fixed Size")
	// EditFixedSizeは可変長配列にしか使えません。
	// 可変長配列の長さをエディタから変更できないようにします。
	TArray<int32> m_editFixedSize = { 1, 2, 3 };

	// Ref:	Only valid on function param declaration.
	//		Value is copied out after function call.
	// Ref指定子は関数の引数にしか宣言できません。
	// この指定子をつけた引数はその値を関数が呼ばれた後も保存します。
	int32 m_ref = 0;
	void meaninglessFunction(UPROPERTY(Ref)int32 reference);

	// Export:	Only useful for object properties (or arrays of objects). 
	//			Indicates that the object assigned to this property should be exported in its entirety as a subobject block when the object is copied (for copy/paste) or exported to T3D,
	//			as opposed to just outputting the object reference itself.
	UPROPERTY(Export)
	UObject* m_export;

	// BlueprintAssignable:	This specifier can use with Multicast Delegates only.
	//						Exposes the property for assigning in Blueprints.
	UPROPERTY(BlueprintAssignable, Category = "Delegate")
	// この指定子はマルチキャストデリゲート型でしか使えません。
	// BlueptrintAssignableで、この変数をブループリントにバインド可能なデリゲートとして公開することができます。
	FmeaninglessDelegate m_blueprintAssignable;

	// BlueprintCallable:	This specifier can use with Multicast Delegates only.
	//						This property should be exposed for calling in Blueprint code.
	UPROPERTY(BlueprintCallable, Category = "Delegate")
	// この指定子はマルチキャストデリゲート型でしか使えません。
	// BlueptrintCallableで、この変数をブループリントでコール可能なデリゲートとして公開することができます。
	FmeaninglessDelegate m_blueprintCallable;

	// Config:	This property should be loaded/saved to ini file as permanent profile.
	UPROPERTY(Config = Game)
	// Configで指定されたこの変数は指定の.iniファイルへ永続的な数値としてセーブアンドロードされなければなりません。
	int32 m_config;

	// GlobalConfig:	This is same as Config.
	//					But this property load config from base class, not subclass.
	UPROPERTY(GlobalConfig)
	// Configと同じですが、必ずベースクラスから読み込まれるようになります。
	// サブクラスからは読み込まれません。
	int32 m_globalConfig;

	// Transient:	Property is transient: shouldn't be saved, zero-filled at load time. Opposite of the SaveGame specifier.
	UPROPERTY(Transient, BlueprintReadOnly)
	// Transientで一時的な変数にすることができます。
	// この変数はセーブできず、ロード時に必ず0が入ります。
	// SaveGame指定子と同時には扱えません。
	int32 m_transient;
};

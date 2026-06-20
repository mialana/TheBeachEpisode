// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TheBeachEpisode : ModuleRules
{
	public TheBeachEpisode(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"TheBeachEpisode",
			"TheBeachEpisode/Variant_Platforming",
			"TheBeachEpisode/Variant_Platforming/Animation",
			"TheBeachEpisode/Variant_Combat",
			"TheBeachEpisode/Variant_Combat/AI",
			"TheBeachEpisode/Variant_Combat/Animation",
			"TheBeachEpisode/Variant_Combat/Gameplay",
			"TheBeachEpisode/Variant_Combat/Interfaces",
			"TheBeachEpisode/Variant_Combat/UI",
			"TheBeachEpisode/Variant_SideScrolling",
			"TheBeachEpisode/Variant_SideScrolling/AI",
			"TheBeachEpisode/Variant_SideScrolling/Gameplay",
			"TheBeachEpisode/Variant_SideScrolling/Interfaces",
			"TheBeachEpisode/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}

#include "stdafx.h"
#include "Game.h"
#include "wiInitializer.h"
#include "wiRenderer.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Initialize()
{

	MainComponent::Initialize();

	infoDisplay.active = true;
	infoDisplay.watermark = true;
	infoDisplay.fpsinfo = false;
	infoDisplay.cpuinfo = false;

	wiInitializer::InitializeComponents(
		wiInitializer::WICKEDENGINE_INITIALIZE_RENDERER
		| wiInitializer::WICKEDENGINE_INITIALIZE_IMAGE
		| wiInitializer::WICKEDENGINE_INITIALIZE_FONT
		| wiInitializer::WICKEDENGINE_INITIALIZE_SOUND
		| wiInitializer::WICKEDENGINE_INITIALIZE_MISC
		);

	wiRenderer::VSYNC = false;
	wiRenderer::EMITTERSENABLED = true;
	wiRenderer::HAIRPARTICLEENABLED = true;
	wiRenderer::setRenderResolution(wiRenderer::GetScreenWidth(), wiRenderer::GetScreenHeight());
	wiRenderer::SetDirectionalLightShadowProps(1024, 2);
	wiRenderer::SetPointLightShadowProps(3, 512);
	wiRenderer::SetSpotLightShadowProps(3, 512);
	wiRenderer::DX11 = false;
	wiRenderer::physicsEngine = new wiBULLET();


	wiFont::addFontStyle("basic");
	wiInputManager::addXInput(new wiXInput());
}


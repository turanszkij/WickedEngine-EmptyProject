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
	wiRenderer::SHADOWMAPRES = 1024;
	wiRenderer::POINTLIGHTSHADOW = 6;
	wiRenderer::POINTLIGHTSHADOWRES = 512;
	wiRenderer::SOFTSHADOW = 2;
	wiRenderer::DX11 = false;
	wiRenderer::physicsEngine = new wiBULLET();
}
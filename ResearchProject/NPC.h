#pragma once
#include <SFML/Graphics.hpp>
#include "RichText.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <algorithm>
#include <iomanip>
#include <array>
#include <sstream>
#include <chrono>
#include <ctime>
#include <cmath>



class NPC
{
public:
	NPC(sf::RenderWindow& t_window ,sf::Font& t_font);
	~NPC();

	int WIDTH = 1920;
	int HEIGHT = 1080;

	//++++++++++SET UP FUNCTIONS ++++++++++
	void setUpNpcStart(int t_ID);
	void setUpNpc(int t_ID);
	void setUpGAvar(int t_RT, int t_Age);//set up Genetic Alg

	//++++++++++GET FUNCTIONS ++++++++++
	sf::Vector2f getPos();
	int getID();
	float getSize();
	sf::Vector2f getSizeTexture();
	int getGender();
	int getAge();
	int getGenertaion();
	std::chrono::duration<double> getReproductionCooldown();
	std::array<float, 4> getDNA();
	bool isAlive();

	float GetSpeedStatistic();
	float GetStrStatistic();
	float GetIntStatistic();
	float GetSizeStatistic();


	void takeHealth(int t_reduction);


	//++++++++++SET FUNCTIONS ++++++++++
	void setPosition(sf::Vector2f t_pos);
	void setEndPosition(sf::Vector2f t_pos);
	void setDNA(std::array<float, 4> t_DNA);
	void setGenertaion(int t_gen);
	void setGender(int t_gender);

	//++++++++++FUNCTIONS ++++++++++
	void Draw();
	void DrawStatistics();
	void Update();
	int randomNumber(int t_max, int t_min);//make a random number 
	void resetReproductionTimer();

	//  put into main system or set up gn Function_
	int REPRODUCTION_TIME;
	int AGE_CAP;



	std::chrono::steady_clock::time_point m_StartTimeReproduction;
	std::chrono::steady_clock::time_point m_CurrentTimeReproduction;
	std::chrono::duration<double> m_elapsedtimeReproduction;


	std::chrono::steady_clock::time_point m_StartTimeAGE;
	std::chrono::steady_clock::time_point m_CurrentTimeAGE;
	std::chrono::duration<double> m_elapsedtimeAGE;
private:
	//text and displays;
	sf::Font m_font;
	sf::RenderWindow& m_window;

	bool m_alive = true;
	int m_ID = NULL;

	int m_generation = 0;//generation of the NPC
	int m_gender = 0; // 0 = female     1 = male
	int m_age = 0;
	int m_runningAge = 0;

	int m_health = 100;

	int m_deathChance;

	//variables for genetic algorithm
	float m_speed;
	float m_strength;
	float m_intelligence;
	float m_size;

	float sizeRounded;
	float m_sizeScale;
	float m_speedScale;

	bool m_SequenceComplete = false; // when the end goal has been reached ------------------------------------------------------------------------------------------------------------------------------------

	//DNA sequence 
	sfe::RichText m_DNAString;
	std::stringstream m_speedStream;
	std::stringstream m_strengthStream;
	std::stringstream m_intelligenceStream;
	std::stringstream m_sizeStream;

	std::array<float, 4>  m_DNA;

	float m_Statistic_cap = 100;

	//++++++++++++++++++++++++TEXT+++++++++++++++++++++
	sf::Text m_DNAText;
	sf::Text m_GenerationText;
	sf::Text m_AgeText;

	//Health Bar 
	sf::RectangleShape m_healthBarBase;
	sf::RectangleShape m_healthBarFront;

	//sprite Visual
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	//+++++++++++++++++++NPC AREA+++++++++++++++++++++
	//positions 
	sf::Vector2f m_position;
	sf::Vector2f m_endPosition;
	sf::Vector2f m_penSize;


	void wander();
};

#pragma once
#include <iostream>
#include <string>
#include "logos.h"

using namespace std;

//Contains all relevant play data needed for the influence algorithm and for the visualization 
class Play
{
	static Logos nflLogos;
	// Used for algorithm
	string date;
	int yardsGained;
	bool touchdown;
	string playType;
	int yrdLine;
	bool sp;
	bool interception;
	bool fumble;
	float home_WP_Pre;
	float home_WP_Post;
	float away_WP_Pre;
	float away_WP_Post;

	// Used for display
	string homeTeam;
	string awayTeam;
	string teamWithBall;
	string homeTeamScore;
	string awayTeamScore;
	string quarter;
	string textTimeRemaining;
	string timeRemaining;
	string playDescription;
	string down;
	string ydsToGo;
	float influence;
public:
	//Constructor
	Play(string homeTeam_, string awayTeam_, string homeTeamScore_, string awayTeamScore_, string quarter_, string timeRemaining_, string playDescription_, string down_, string ydsToGo_, 
	string date_, string yardsGained_, string touchdown_, string playType_, string yrdLine_, string sp_, string interception_, string fumble_, string home_WP_Pre_, string home_WP_Post_, string away_WP_Pre_, string away_WP_Post_, string textTimeRemaining_, string teamWithBall_);
	//Draws play data to the screen
	void draw(sf::RenderWindow& window);
	//Calculates influence
	void calcInfluence();
	//Returns the influence of the play
	float getInfluence() const;
	//Returns description of the play
	string getDescription() const;

	// For use in AVL tree
	Play* left;
	Play* right;
	int bf;
	void setBF();
	int treeHeight(Play* root);
};

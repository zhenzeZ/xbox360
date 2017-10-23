#include "XBOX360CONTROLLER.h"

Xbox360Controller::Xbox360Controller() :
	sf_Joystick_index(0u)
{
	initSprites();
}

Xbox360Controller::~Xbox360Controller() {

}

void Xbox360Controller::update() {
	sf::Joystick::update();
	lastButton();

	if (m_currentState.A) {
		m_previousState.A = true;
	}
	else
	{
		m_previousState.A = false;
	}

	if (m_currentState.B) {
		m_previousState.B = true;
	}
	else
	{
		m_previousState.B = false;
	}

	if (m_currentState.X) {
		m_previousState.X = true;
	}
	else
	{
		m_previousState.X = false;
	}

	if (m_currentState.Y) {
		m_previousState.Y = true;
	}
	else
	{
		m_previousState.Y = false;
	}

	if (m_currentState.LB) {
		m_previousState.LB = true;
	}
	else
	{
		m_previousState.LB = false;
	}

	if (m_currentState.RB) {
		m_previousState.RB = true;
	}
	else
	{
		m_previousState.RB = false;
	}

	if (m_currentState.LeftThumbStickClick) {
		m_previousState.LeftThumbStickClick = true;
	}
	else
	{
		m_previousState.LeftThumbStickClick = false;
	}

	if (m_currentState.RightThumbStickClick) {
		m_previousState.RightThumbStickClick = true;
	}
	else
	{
		m_previousState.RightThumbStickClick = false;
	}

	if (m_currentState.DpadUp) {
		m_previousState.DpadUp = true;
	}
	else
	{
		m_previousState.DpadUp = false;
	}

	if (m_currentState.DpadDown) {
		m_previousState.DpadDown = true;
	}
	else
	{
		m_previousState.DpadDown = false;
	}

	if (m_currentState.DpadLeft) {
		m_previousState.DpadLeft = true;
	}
	else
	{
		m_previousState.DpadLeft = false;
	}

	if (m_currentState.DpadRight) {
		m_previousState.DpadRight = true;
	}
	else
	{
		m_previousState.DpadRight = false;
	}

	if (m_currentState.Start) {
		m_previousState.Start = true;
	}
	else
	{
		m_previousState.Start = false;
	}

	if (m_currentState.Back) {
		m_previousState.Back = true;
	}
	else
	{
		m_previousState.Back = false;
	}

	if (m_currentState.Xbox) {
		m_previousState.Xbox = true;
	}
	else
	{
		m_previousState.Xbox = false;
	}

	// check the left tigger vaule when the vaule great than 5 turn it to text
	if (m_currentState.LTtigger >= 5) // 5 is blance the of machine and human control
	{
		float LTnum = m_currentState.LTtigger;
		text[15].setString(toString(LTnum));
		text[15].setPosition(100, 70);
	}
	else
	{
		text[15].setString("");
	}

	// check the right tigger vaule when the vaule great than 5 turn it to text
	if (m_currentState.RTtigger >= 5){
		float RTnum = m_currentState.RTtigger;
		text[14].setString(toString(RTnum));
		text[14].setPosition(550, 70);
	}
	else
	{
		text[14].setString("");
	}

	if (m_currentState.RighThumbStick.x >= 10 || m_currentState.RighThumbStick.x <= -10) // 10 is blance the deviation of machine and human control
	{
		float Rx = m_currentState.RighThumbStick.x;
		text[16].setString("x:" + toString(Rx));
		text[16].setPosition(500, 480);
	}
	else
	{
		text[16].setString("");
	}

	if (m_currentState.RighThumbStick.y >= 10 || m_currentState.RighThumbStick.y <= -10) {
		float Ry = m_currentState.RighThumbStick.y;
		text[17].setString("y:" + toString(Ry));
		text[17].setPosition(500, 495);
	}
	else
	{
		text[17].setString("");
	}

	if (m_currentState.LeftThumbStick.x >= 10 || m_currentState.LeftThumbStick.x <= -10) {
		float Lx = m_currentState.LeftThumbStick.x;
		text[18].setString("x:" + toString(Lx));
		text[18].setPosition(100, 320);
	}
	else
	{
		text[18].setString("");
	}

	if (m_currentState.LeftThumbStick.y >= 10 || m_currentState.LeftThumbStick.y <= -10) {
		float Ly = m_currentState.LeftThumbStick.y;
		text[19].setString("y:" + toString(Ly));
		text[19].setPosition(100, 335);
	}
	else
	{
		text[19].setString("");
	}
}

bool Xbox360Controller::connect() {
	return isConnected();
}

bool Xbox360Controller::isConnected() {
	if (sf::Joystick::isConnected(sf_Joystick_index)) {
		return true;
	}
	else {
		return false;
	}
}

void Xbox360Controller::render(sf::RenderWindow & window) {
	if (m_previousState.Y) {
		window.draw(text[0]);
	}

	if (m_previousState.X) {
		window.draw(text[1]);
	}

	if (m_previousState.B) {
		window.draw(text[2]);
	}

	if (m_previousState.A) {
		window.draw(text[3]);
	}

	if (m_previousState.LB) {
		window.draw(text[4]);
	}

	if (m_previousState.RB) {
		window.draw(text[5]);
	}

	if (m_previousState.LeftThumbStickClick) {
		window.draw(text[6]);
	}

	if (m_previousState.RightThumbStickClick) {
		window.draw(text[7]);
	}

	window.draw(text[8]); // draw letter for Up Dpad buttom 
	window.draw(text[9]);
	window.draw(text[10]);
	window.draw(text[11]);
	

	if (m_previousState.Start) {
		window.draw(text[12]);
	}

	if (m_previousState.Back) {
		window.close(); // when back button pressed, close the window
	}

	window.draw(text[14]); // display axis of RT
	window.draw(text[15]); // display axis of LT

	window.draw(text[16]); // display axis position of Right Thumb Stick
	window.draw(text[17]); // display axis position of Left Thumb Stick
	window.draw(text[18]); // display axis position of Right Thumb Stick
	window.draw(text[19]); // display axis position of Left Thumb Stick

	window.draw(text[20]); // display last button
}

void Xbox360Controller::lastButton() {
	if (!m_currentState.A && m_previousState.A)
	{
		text[20].setString("Last botton pressed is A");
	}

	if (!m_currentState.B && m_previousState.B)
	{
		text[20].setString("Last botton pressed is B");
	}

	if (!m_currentState.X && m_previousState.X)
	{
		text[20].setString("Last botton pressed is X");
	}

	if (!m_currentState.Y && m_previousState.Y)
	{
		text[20].setString("Last botton pressed is Y");
	}
}

void Xbox360Controller::checkButton() {
	m_currentState.A = sf::Joystick::isButtonPressed(sf_Joystick_index, 0u);
	m_currentState.B = sf::Joystick::isButtonPressed(sf_Joystick_index, 1u);
	m_currentState.X = sf::Joystick::isButtonPressed(sf_Joystick_index, 2u);
	m_currentState.Y = sf::Joystick::isButtonPressed(sf_Joystick_index, 3u);
	m_currentState.LB = sf::Joystick::isButtonPressed(sf_Joystick_index, 4u);
	m_currentState.RB = sf::Joystick::isButtonPressed(sf_Joystick_index, 5u);
	m_currentState.LeftThumbStickClick = sf::Joystick::isButtonPressed(sf_Joystick_index, 8u);
	m_currentState.RightThumbStickClick = sf::Joystick::isButtonPressed(sf_Joystick_index, 9u);
	m_currentState.Start = sf::Joystick::isButtonPressed(sf_Joystick_index, 7u);
	m_currentState.Back = sf::Joystick::isButtonPressed(sf_Joystick_index, 6u);
	m_currentState.RTtigger = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Z);
	m_currentState.LTtigger = -m_currentState.RTtigger;

	m_currentState.LeftThumbStick.x = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::X);
	m_currentState.LeftThumbStick.y = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::Y);
	m_currentState.RighThumbStick.x = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::U);
	m_currentState.RighThumbStick.y = sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::R);

	if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::PovX) > 1) 
	{
		m_currentState.DpadRight = true;
		text[8].setString("Up");
	}
	else 
	{
		m_currentState.DpadRight = false;
		text[8].setString(" ");
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::PovX) < -1)
	{
		m_currentState.DpadLeft = true;
		text[9].setString("Down");
	}
	else 
	{
		m_currentState.DpadLeft = false;
		text[8].setString(" ");
	}

	if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::PovY) > 1) 
	{
		m_currentState.DpadUp = true;
		text[10].setString("Right");
	}
	else 
	{
		m_currentState.DpadUp = false;
		text[10].setString(" ");
	}
	
	if (sf::Joystick::getAxisPosition(sf_Joystick_index, sf::Joystick::PovY) < -1)
	{
		m_currentState.DpadDown = true;
		text[11].setString("Left");
	}
	else 
	{
		m_currentState.DpadDown = false;
		text[11].setString(" ");
	}
}

void Xbox360Controller::initSprites() {
	font.loadFromFile("C:\\Windows\\Fonts\\times.ttf");

	for (int i = 0; i < 22; i++) {
		text[i].setFont(font);
		text[i].setScale(0.7f, 0.7f);
		text[i].setFillColor(sf::Color::Black);
	}

	text[0].setString("Button Y is pressed");
	text[0].setPosition(700, 270);

	text[1].setString("Button X is pressed");
	text[1].setPosition(700, 330);

	text[2].setString("Button B is pressed");
	text[2].setPosition(700, 390);

	text[3].setString("Button A is pressed");
	text[3].setPosition(700, 450);

	text[4].setString("Button LB is pressed");
	text[4].setPosition(690, 120);

	text[5].setString("Button RB is pressed");
	text[5].setPosition(210, 120);

	text[6].setString("Clicked"); // LeftThumbStickClick
	text[6].setPosition(150, 300);

	text[7].setString("Clicked"); // RightThumbStickClick
	text[7].setPosition(400, 500);

	/// <summary>
	/// set position for dpad position
	/// </summary>
	text[8].setPosition(280, 480);

	text[9].setPosition(280, 480);

	text[10].setPosition(280, 500);

	text[11].setPosition(280, 500);
	

	text[12].setString("Start Pressed"); // strat button
	text[12].setPosition(700, 520);

	text[13].setString("Xbox Pressed"); // xobx button
	text[13].setPosition(400, 350);

	if (connect()) { // check connection
		text[21].setString("Controller connected");
	}
	else {
		text[21].setString("Controller not found");
	}

	text[20].setPosition(700, 200);
}

std::string Xbox360Controller::toString(float num) {
	char numString[256];
	sprintf_s(numString, "%f", num);
	return numString;
}
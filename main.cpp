#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<Windows.h>
#include<sstream>

using namespace sf;
using namespace std;

int main()
{
	srand(time(NULL));

	int dx = 1, dy = 1;
	int ballposx = 100, ballposy = 200;
	double p = 0, c = 0;

	Font myfont;
	Text player;
	Text computer;
	Text splayer;
	Text scomputer;
	Text start;
	myfont.loadFromFile("ab.ttf");


	RenderWindow window(VideoMode(1500, 800), "It's SFML? Nope, it's C++ SFML.");

	Texture f;
	f.loadFromFile("field.png");
	Sprite field(f);

	Texture b;
	b.loadFromFile("ball.png");
	Sprite ball(b);
	ball.setPosition(ballposx, ballposy);

	Texture l;
	l.loadFromFile("l.png");
	Sprite left(l);
	left.setPosition(0, 0);

	Texture r;
	r.loadFromFile("r.png");
	Sprite right(r);
	right.setPosition(1153, 0);

	SoundBuffer buffer;
	buffer.loadFromFile("s.way");
	Sound s;
	s.setBuffer(buffer);

	start.setFont(myfont);
	start.setString("Press Enter to start");
	start.setCharacterSize(60);
	start.setColor(Color(0, 255, 0));
	start.setPosition(450, 400);

	while (!Keyboard::isKeyPressed(Keyboard::Enter)) {
		window.draw(start);
		window.display;
	}

	string sss()
	{
		double n;
		stringstream ss;
		ss << n;
		return ss.str();
	}

	while (window.isOpen()) {
		splayer.setFont(myfont);
		splayer.setString("PLAYER: ");
		splayer.setCharacterSize(40);
		splayer.setColor(Color(0, 255, 0));
		splayer.setPosition(100, 700);

		player.setFont(myfont);
		player.setString(sss(p));
		player.setCharacterSize(40);
		player.setColor(Color(0, 255, 0));
		player.setPosition(320, 700);

		scomputer.setFont(myfont);
		scomputer.setString("COMPUTER: ");
		scomputer.setCharacterSize(40);
		scomputer.setColor(Color(0, 255, 0));
		scomputer.setPosition(700, 700);

		computer.setFont(myfont);
		computer.setString(sss(c));
		computer.setCharacterSize(40);
		computer.setColor(Color(0, 255, 0));
		computer.setPosition(940, 700);

		window.setFramerateLimit(0);
		Event e;

		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		ball.move(dx, dy);
		if (ball.getPosition().x < 0 || ball.getPosition().x>1160)dx = -dx;
		if (ball.getPosition().y < 0 || ball.getPosition().y>650)dy = -dy;

		if (Keyboard::isKeyPressed(Keyboard::Up) && left.getPosition().y > 0)left.move(0, -1);
		if (Keyboard::isKeyPressed(Keyboard::Down) && left.getPosition().y < 510)left.move(0, 1);

		if (ball.getPosition().y > left.getPosition().y - 10 &&
			ball.getPosition().y < left.getPosition().y + 170 &&
			ball.getPosition().x == 50 && dx == -1) {
			dx = -dx;
			s.play();
		}

		if (ball.getPosition().y > left.getPosition().y - 10 &&
			ball.getPosition().y < left.getPosition().y + 170 &&
			ball.getPosition().x >-25 && ball.getPosition().x < 50 && dx == -1) {
			dx = -dx;
			dy = -dy;
			s.play();
		}


		if (right.getPosition().y < ball.getPosition().y &&
			right.getPosition().y < 510 &&
			ball.getPosition().x > 780)right.move(0, 1);
		if (right.getPosition().y > ball.getPosition().y &&
			ball.getPosition().x > 780)right.move(0, -1);

		if (ball.getPosition().y > right.getPosition().y - 10 &&
			ball.getPosition().y < right.getPosition().y + 170 &&
			ball.getPosition().x == 1100 && dx == 1) {
			dx = -dx;
			s.play();
		}

		if (ball.getPosition().y > right.getPosition().y - 10 &&
			ball.getPosition().y < right.getPosition().y + 170 &&
			ball.getPosition().x>1100 && ball.getPosition.getTexture < 1175 && dx == 1) {
			dx = -dx;
			dy = -dy;
			s.play();
		}

		if (ball.getPosition().x <= 0) {
			c++;
			ballposx = rand() % 500 + 400;
			ball.setPosition(ballposx, ballposy);
			Sleep(1000);
		}

		if (ball.getPosition().x >= 1160) {
			p++;
			ballposx = rand() % 500 + 400;
			ball.setPosition(ballposx, ballposy);
			Sleep(1000);
		}

		window.clear();
		window.draw(field);
		window.draw(left);
		window.draw(right);
		window.draw(ball);
		window.draw(player);
		window.draw(computer);
		window.draw(splayer);
		window.draw(scomputer);
		window.display();

		printf("\r ball.getPosition().x= %f", ball.getPosition().x);
	}
}

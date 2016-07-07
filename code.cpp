#include <cassert>
#include <deque>
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <stdlib.h>




int main()
{
    float size = 10;
    float posX =0;
    float posY =0;
    int score =1;
    //float hitting =0;
    //float enemiesPosY = 100;
    float enemiesLengte = 30;
    float enemyPosition= 150;
    float enemiesBreedte = 25;
    float timeBullet =0;
    int aantalBullets=0;
    float oneBullet =1;
    int totalEnemies=10;
    int totalEnemiesCreate =0;
    int enemiesPerRij =10;
    int rij;
    int totalEnemyBulletShot =0;
    float enemiesPosYHight=100;
    float enemySpeed =0.05;
    float enemyBulletSizeX = 25;
    float enemyBulletSizeY = 20;
    float playerCollidingPoints=0;
    std::deque<sf::RectangleShape> bullets;
    std::deque<sf::RectangleShape> enemyBullets;
    std::deque<float> playerCollidingPointsDeque;
    std::deque<float> enemyBulletsY;
    std::deque<float> enemiesBulletsY;
    std::deque<float> enemiesBulletsX;
    std::deque<float> movingY;
    std::deque<float> bulletsX;
    std::deque<float> enemiesPosX;
    std::deque<float> enemiesPosY;
    std::deque<sf::RectangleShape> enemies;

  sf::SoundBuffer laserBuffer;
  sf::SoundBuffer explosionBuffer;
  for(int i=0; i<5; ++i)
  {
      playerCollidingPointsDeque[i]=playerCollidingPoints;
      playerCollidingPoints+=10;
      //std::cout<<playerCollidingPointsDeque[i]<< "\n";
  }
  if(!laserBuffer.loadFromFile("laser_Shoot3.wav"))
  {
      std::cout<< "Error loading sound (laser)" << std::endl;
  }
  if(!explosionBuffer.loadFromFile("explosion3.wav"))
  {
      std::cout<< "Error loading sound (explosion)" << std::endl;
  }

  sf::Sound laser;
  sf::Sound explosion;
  laser.setBuffer(laserBuffer);
  explosion.setBuffer(explosionBuffer);
  const int window_size = 800;
  posX = window_size/2;
  posY = window_size-55;
  sf::RenderWindow window(
     sf::VideoMode(window_size, window_size),
     "mt",
     sf::Style::Titlebar | sf::Style::Close);

    //for(int i=0; i < totalEnemies; ++i)
    //
       //enemies.push_back(sf::RectangleShape(sf::Vector2f(enemiesLengte, enemiesBreedte)));

    //}
    rij =enemiesPerRij;
    totalEnemiesCreate += enemiesPerRij;

    for(int i=0; i<totalEnemies; ++i)
    {
        enemies.push_back(sf::RectangleShape(sf::Vector2f(enemiesLengte, enemiesBreedte)));
        enemiesPosX.push_back(enemyPosition);
        enemiesPosY.push_back(enemiesPosYHight);
        assert(i >= 0);
        assert(i < static_cast<int>(enemies.size()));
        enemies[i].setOrigin(sf::Vector2f(0,0));
        enemies[i].setPosition(enemiesPosX[i], enemiesPosY[i]);
        enemies[i].setFillColor(sf::Color(255,0,0));
        enemyPosition +=50;

    }


    while(window.isOpen())
        {
            sf::Event event;


            while(window.pollEvent(event))
            {
                switch(event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
                }
            }


        for(int i=0; i<totalEnemies; ++i)
        {

            enemiesPosX[i] += enemySpeed;
            enemies[i].setPosition(enemiesPosX[i], enemiesPosY[i]);
            if(window_size-55 < enemiesPosX[i])
            {
                enemySpeed += 0.004;
                enemySpeed *=-1;
                for(int j=0; j<totalEnemies; ++j)
                enemiesPosY[j] +=40;

            }

            if(30 > enemiesPosX[i])
            {
                enemyPosition = 30;
                for(int k=totalEnemies; k<totalEnemies +10; ++k)
                {
                    //assert(i >= 0);
                    //assert(i < static_cast<int>(enemies.size() +10));
                    enemies.push_back(sf::RectangleShape(sf::Vector2f(enemiesLengte, enemiesBreedte)));
                    enemiesPosX.push_back(enemyPosition);
                    enemiesPosY.push_back(enemiesPosYHight);
                    enemies[k].setOrigin(sf::Vector2f(0,0));
                    enemies[k].setPosition(enemiesPosX[k], enemiesPosY[k]);
                    enemies[k].setFillColor(sf::Color(255,0,0));
                    enemyPosition +=50;

                }

                enemySpeed -= 0.002;
                enemySpeed *=-1;
                totalEnemies+=10;
//              for(int j=0; j<totalEnemies; ++j)
  //            enemiesPosY[j] +=40;

                //enemiesPerRij +=10;
                totalEnemiesCreate +=10;

            }
        }
        totalEnemies = enemies.size();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (size/2)<posX)
        {
              posX -= 0.23;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (window_size-(size/2))>posX)
        {
              posX += 0.23;
        }

        oneBullet +=0.001;

        if(oneBullet >=1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            oneBullet =0;
            laser.play();
            bullets.push_back(sf::RectangleShape(sf::Vector2f(size/3,size)));
            movingY.push_back(0);

            bulletsX.push_back(posX);
        }
        //Check for stats

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && oneBullet >= 1)
        {
            oneBullet =0;
            std::cout<<"bulletPosition: "<<enemyBullets[0].getPosition().y << "\n";
            std::cout<<"bulletAmount: " <<enemyBullets.size()<< "\n";
            std::cout<<"Score: "<<score<< "\n";

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
            return 0;
        }


        for(unsigned i=0; i< bullets.size(); ++i)
        {
            movingY[i] += 0.25;
            bullets[i].setPosition(bulletsX[i], posY- movingY[i]);
            bullets[i].setOrigin(sf::Vector2f(size/3/2,0));
        }

        sf::RectangleShape player(sf::Vector2f(40,25));
        player.setPosition(posX, posY);
        player.setOrigin(sf::Vector2f(0,0));

        //sf::RectangleShape enemies(sf::Vector2f(enemiesLengte,enemiesBreedte));
        //enemies.setPosition(enemiesPosX, enemiesPosY);

        //enemies.setFillColor(sf::Color(255, 0, 0));

        for(int i=0; i<totalEnemies; ++i){
            //std::cout<< "enemy" << i << "y position = " <<enemiesPosY[i] << "\n";
            for(unsigned j=0; j<bullets.size(); ++j){
                if(enemiesPosX[i] <bulletsX[j] && enemiesPosX[i] + enemiesLengte>bulletsX[j])
                {
                    if(enemiesPosY[i] + enemiesBreedte > bullets[j].getPosition().y && enemiesPosY[i] < bullets[j].getPosition().y)
                    {

                        enemyBullets.push_back(sf::RectangleShape(sf::Vector2f(enemyBulletSizeX, enemyBulletSizeY)));
                        enemyBulletsY.push_back(enemiesPosY[i]);
                        enemiesBulletsX.push_back(enemiesPosX[i]);
                        totalEnemyBulletShot +=1;
                        //std::cout<< "enemy" << i << "y position = " <<enemiesPosY[i] << "\n";
                        //std::cout<<"hit \n";
                        explosion.play();
                        totalEnemies -=1;
                        score +=1;
                        enemies[i] = enemies[0];
                        enemiesPosX[i] = enemiesPosX[0];
                        enemiesPosY[i] = enemiesPosY[0];
                        enemiesPosX.pop_front();
                        enemiesPosY.pop_front();
                        enemies.pop_front();
                        bullets[j] = bullets[0];
                        movingY[j] = movingY[0];
                        bulletsX[j] = bulletsX[0];
                        bullets.pop_front();
                        movingY.pop_front();
                        bulletsX.pop_front();


                            //Verder werken enzo

                     }
                }
            }
        }

        for(unsigned i=0; i<enemyBullets.size(); ++i)
        {
            enemyBulletsY[i]+=0.1;
            enemyBullets[i].setFillColor(sf::Color(255,0,0));
            enemyBullets[i].setPosition(enemiesBulletsX[i]+5, enemyBulletsY[i]+5);
            enemyBullets[i].setOrigin(sf::Vector2f(10,10));

            //std::cout<<enemyBullets[i].getPosition().y<< "\n";
            for(int j=0; j<5; ++j)
            {
            if(enemiesBulletsX[i] < posX +playerCollidingPointsDeque[j] && enemiesBulletsX[i]  + 40>posX)
            {
                if(enemyBulletsY[i] > posY-20 && enemyBulletsY[i] < posY)
                {
                    std::cout<<"Game over! \n";
                    std::cout<<"Score: " << score << "\n";
                    return 0;
                }
            }
            }
        }
        //draw everything
        window.clear();
        window.draw(player);
        for(const auto enemy: enemies)
        window.draw(enemy);

        for(const auto bullet: bullets)
        window.draw(bullet);

        for(const auto bulletEnemy: enemyBullets)
        window.draw(bulletEnemy);


        //for(unsigned i=0; i< bullets.size(); ++i)
        //{
        //    window.draw(bullets[i]);
        //}
        window.display();

        if(bullets.size() >1)
        {
            if (bullets[0].getPosition().y < -100)
            {
                bullets.pop_front();
                movingY.pop_front();
                bulletsX.pop_front();
            }
        }
        if(enemyBullets.size() >1)
        {
            if (enemyBullets[0].getPosition().y > window_size +100)
            {
                enemyBullets.pop_front();
                enemiesBulletsX.pop_front();
                enemyBulletsY.pop_front();
            }
        }
        for(unsigned i=0; i<enemies.size(); ++i)
        {
            if(enemies[i].getPosition().y > window_size-100)
            {
                std::cout<<"Game over! \n";
                std::cout<<"Score: " << score << "\n";
            return 0;
            }

        }
    }
}



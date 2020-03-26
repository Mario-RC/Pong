## Pong

#### Setup

Create the directory called `build`. Enter and execute the following commands in the terminal:
```
`cmake ..`
`make`
```

The directory `src` will be created. Enter and execute the following commands in the terminal:
```
./logger
./loggerFIFO
./server
./bot
./customer
```

Write a name and you're ready to play.

#### Rules

```
1- Try to bounce the ball with the racket.
2- Racket movement player1: Up letter 'w', Down letter 's'.
   Racket movement player2: Up letter 'o', Down letter 'l'.
3- If the ball touches the wall immediately behind the racket, the opponent will receive a point.
4- When any of the two players reaches 3 points, a second sphere appears.
5- When any of the two players reaches 5 points, the balls become pulsating balls (they vary their radius constantly).
6- The rackets can shoot (player1 letter 'd', player2 letter 'k').
7- If a player reaches the opposite player with a shot, the player who receives the shot will reduce the length of his racket by 40% of the original size.
8- The game ends when one of the two players reaches 10 points.
9- There is a Bot mode (artificial player), racket1 will play automatically.
10- The Bot will take control if player2 does not press any key for 10 seconds. To retake control, just press any action key on racket2.
```


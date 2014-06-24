var Direction = {
    UP: 38,
    RIGHT: 39,
    DOWN: 40,
    LEFT: 37
};
var Common = {
    width: 20,
    height: 20,
    speed: 250,
    workThread: null
};
var Position = function(x, y) {
    this.X = 0;
    this.Y = 0;
    if (arguments.length >= 1)
        this.X = x;
    if (arguments.length >= 2)
        this.Y = y;
};
var Snake = function() {
    this.isDone = false;
    this.dir = Direction.RIGHT;
    this.pos = new Array(new Position());
    this.Move = function() {
        document.getElementById("box_" + this.pos[0].X + "_" + this.pos[0].Y).className = "";
        for (var i = 0; i < this.pos.length - 1; i++) {
            this.pos[i].X = this.pos[i + 1].X;
            this.pos[i].Y = this.pos[i + 1].Y;
        }
        var head = this.pos[this.pos.length - 1];
        switch (this.dir) {
            case Direction.UP:
                head.Y--;
                break;
            case Direction.RIGHT:
                head.X++;
                break;
            case Direction.DOWN:
                head.Y++;
                break;
            case Direction.LEFT:
                head.X--;
                break;
        }
        this.pos[this.pos.length - 1] = head;
        for (var i = 0; i < this.pos.length; i++) {
            var isExits = false;
            for (var j = i + 1; j < this.pos.length; j++)
                if (this.pos[j].X == this.pos[i].X && this.pos[j].Y == this.pos[i].Y) {
                    isExits = true;
                    break;
                }
            if (isExits) {
                this.Over();
                break;
            }
            var obj = document.getElementById("box_" + this.pos[i].X + "_" + this.pos[i].Y);
            if (obj)
                obj.className = "snake";
            else {
                this.Over();
                break;
            }
        }
        this.isDone = true;
    };
    this.Over = function() {
        clearInterval(Common.workThread);
        alert("Game Over!");
    };
    this.Eat = function(food) {
        var head = this.pos[this.pos.length - 1];
        var isEat = false;
        switch (this.dir) {
            case Direction.UP:
                if (head.X == food.pos.X && head.Y == food.pos.Y + 1)
                    isEat = true;
                break;
            case Direction.RIGHT:
                if (head.Y == food.pos.Y && head.X == food.pos.X - 1)
                    isEat = true;
                break;
            case Direction.DOWN:
                if (head.X == food.pos.X && head.Y == food.pos.Y - 1)
                    isEat = true;
                break;
            case Direction.LEFT:
                if (head.Y == food.pos.Y && head.X == food.pos.X + 1)
                    isEat = true;
                break;
        }
        if (isEat) {
            this.pos[this.pos.length] = new Position(food.pos.X, food.pos.Y);
            food.Create(this.pos);
        }
    };
    this.SetDir = function(dir) {
        switch (dir) {
            case Direction.UP:
                if (this.isDone && this.dir != Direction.DOWN) {
                    this.dir = dir;
                    this.isDone = false;
                }
                break;
            case Direction.RIGHT:
                if (this.isDone && this.dir != Direction.LEFT) {
                    this.dir = dir;
                    this.isDone = false;
                }
                break;
            case Direction.DOWN:
                if (this.isDone && this.dir != Direction.UP) {
                    this.dir = dir;
                    this.isDone = false;
                }
                break;
            case Direction.LEFT:
                if (this.isDone && this.dir != Direction.RIGHT) {
                    this.dir = dir;
                    this.isDone = false;
                }
                break;
        }
    };
};
var Food = function() {
    this.pos = new Position();
    this.Create = function(pos) {
        document.getElementById("box_" + this.pos.X + "_" + this.pos.Y).className = "";
        var x = 0, y = 0, isCover = false;
        do {
            x = parseInt(Math.random() * (Common.width - 1));
            y = parseInt(Math.random() * (Common.height - 1));
            isCover = false;
            if (pos instanceof Array) {
                for (var i = 0; i < pos.length; i++) {
                    if (x == pos[i].X && y == pos[i].Y) {
                        isCover = true;
                        break;
                    }
                }
            }
        } while (isCover);
        this.pos = new Position(x, y);
        document.getElementById("box_" + x + "_" + y).className = "food";
    };
};
var Control = function() {
    this.snake = new Snake();
    this.food = new Food();
    var control = this;
    this.Init = function(pid) {
        var html = [];
        html.push("<table>");
        for (var y = 0; y < Common.height; y++) {
            html.push("<tr>");
            for (var x = 0; x < Common.width; x++) {
                html.push('<td id="box_' + x + "_" + y + '"> </td>');
            }
            html.push("</tr>");
        }
        html.push("</table>");
        document.getElementById(pid).innerHTML = html.join("");
    };
    this.Start = function() {
        this.MoveSnake = function(ev) {
            var evt = window.event || ev;
            control.snake.SetDir(evt.keyCode);
        };
        try {
            document.attachEvent("onkeydown", control.MoveSnake);
        } catch (e) {
            document.addEventListener("keydown", control.MoveSnake, false);
        }
        control.food.Create();
        Common.workThread = setInterval(function() {
            control.snake.Eat(control.food);
            control.snake.Move();
        }, Common.speed);
    };
};
var Main = function() {
    var control = new Control();
    var snake = new Snake;
    window.onload = function() {
        control.Init("panel");
        document.getElementById("btnStart").onclick = function() {
            control.Start();
            this.disabled = true;
            document.getElementById("selSpeed").disabled = true;
            document.getElementById("selSize").disabled = true;
        };
        document.getElementById("selSpeed").onchange = function() {
            Common.speed = 100 / this.value;
        };
        document.getElementById("selSize").onchange = function() {
            Common.width = this.value;
            Common.height = this.value;
            control.Init("panel");
        };
    };
};

Main();

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Pomodoro Timer</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      text-align: center;
    }
    #timer {
      font-size: 36px;
      margin-top: 50px;
    }
    #buttons {
      margin-top: 20px;
    }
  </style>
</head>
<body>
  <h1>Pomodoro Timer</h1>
  <div id="timer">25:00</div>
  <div id="buttons">
    <button onclick="startTimer()">Start</button>
    <button onclick="pauseTimer()">Pause</button>
    <button onclick="resetTimer()">Reset</button>
  </div>

  <script>
    let timer;
    let minutes = 25;
    let seconds = 0;
    let isPaused = false;

    function startTimer() {
      if (!timer) {
        timer = setInterval(updateTimer, 1000);
      }
    }

    function pauseTimer() {
      clearInterval(timer);
      timer = null;
      isPaused = true;
    }

    function resetTimer() {
      clearInterval(timer);
      timer = null;
      minutes = 25;
      seconds = 0;
      updateDisplay();
    }

    function updateTimer() {
      if (isPaused) {
        return;
      }

      if (seconds === 0) {
        if (minutes === 0) {
          clearInterval(timer);
          timer = null;
          return;
        }
        minutes--;
        seconds = 59;
      } else {
        seconds--;
      }

      updateDisplay();
    }

    function updateDisplay() {
      let displayMinutes = minutes < 10 ? "0" + minutes : minutes;
      let displaySeconds = seconds < 10 ? "0" + seconds : seconds;
      document.getElementById('timer').innerText = displayMinutes + ":" + displaySeconds;
    }
  </script>
</body>
</html>

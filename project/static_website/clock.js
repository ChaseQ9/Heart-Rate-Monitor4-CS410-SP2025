// Program name: clock.js
// Description: This program displays the current date and time in a specific format.

function updateClock() {

    // Get the current date and time
    const now = new Date();
  
    // Format the date and time
    const options = { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' };

    // "undefined" locale means the default locale of the browser
    const dateStr = now.toLocaleDateString(undefined, options);
  
    // Format the time in a human-readable string based on the browser's locale
    const timeStr = now.toLocaleTimeString();
  
    // Update the content of HTML elements with IDs 'date' and 'time'
    document.getElementById('date').textContent = dateStr;
    document.getElementById('time').textContent = timeStr;
  }
  
  // Initial call to display the clock immediately
  updateClock();

  // Update the clock every second
  setInterval(updateClock, 1000);
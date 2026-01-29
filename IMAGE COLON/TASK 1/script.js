
const weatherData = {
  Chennai: { temp: "33°C", condition: "Sunny" },
  Bangalore: { temp: "25°C", condition: "Rainy" },
  Delhi: { temp: "19°C", condition: "Hazy" },
  Mumbai: { temp: "29°C", condition: "Humid" },
  Kolkata: { temp: "27°C", condition: "Thunderstorms" }
};

document.getElementById("checkBtn").addEventListener("click", () => {
  const city = document.getElementById("cityInput").value.trim();
  const display = document.getElementById("weatherDisplay");

  if (city && weatherData[city]) {
    const { temp, condition } = weatherData[city];
    display.innerHTML = `
      <p>🌆 <strong>${city}</strong></p>
      <p>🌡 Temperature: ${temp}</p>
      <p>☁ Condition: ${condition}</p>
    `;
    display.classList.remove("error");
  } else {
    display.innerHTML = "❌ Sorry, city not found!";
    display.classList.add("error");
  }
});
    
    



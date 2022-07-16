
enum WeatherType {
	Sunny, Cloudy, Stormy, Rainy, Snowfall
};

class Weather {
private:
	WeatherType type;
public:
	Weather();
	virtual ~Weather();

	inline void setType(WeatherType type) { this->type = type; }

	inline WeatherType getType() const { return this->type; }
};
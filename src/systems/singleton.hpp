#pragma once

// Simply a singleton
template<typename T>
class Singleton {
protected:
	Singleton(){}

public:

	Singleton(const Singleton&) = delete;

	void operator = (const Singleton&) = delete;

	static T& get() {
		static T instance;
		return instance;
	}
};
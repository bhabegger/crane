PORT=/dev/ttyACM0
TARGET_DIR=build/crane
ARDUINO=arduino --pref build.path=${TARGET_DIR} --board arduino:avr:uno --port ${PORT}

verify: install-deps
	mkdir -p ${TARGET_DIR}
	${ARDUINO} --verify src/crane/crane.ino

upload: install-deps
	fuser -k ${PORT} || true
	mkdir -p build
	${ARDUINO} --upload src/crane/crane.ino

install-deps:
	${ARDUINO} --install-library Servo

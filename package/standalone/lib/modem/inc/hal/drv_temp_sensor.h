#ifndef __DRV_TEMP_SENSOR_H__
#define __DRV_TEMP_SENSOR_H__

#define TEMP_SENSOR_I2C_CHANNEL I2C_0
#define TEMP_SENSOR_SCL		GPIO_31
#define TEMP_SENSOR_SDA		GPIO_30

#define TMP103B_SLAVE_ADDRESS	0x71
#define MAX31875R0_SLAVE_ADDRESS	0x48

typedef struct {
	int8_t temperature;
	int16_t delta;
} TEMP_DELTA_TBL;

#define TEMP_TABLE_MAX 14
static const TEMP_DELTA_TBL tdelta_tbl[TEMP_TABLE_MAX] = {
	//temperature, delta*100
	{-45, 250},
	{-35, 210},
	{-25, 190},
	{-15, 150},
	{-5, 120},
	{5, 80},
	{15, 40},
	{25, 0},
	{35, -40},
	{45, -100},
	{55, -160},
	{65, -210},
	{75, -270},
	{85, -310},
};

enum i2c_temp_sensor_type {
	TEMP_SENSOR_TYPE_TMP103B,
	TEMP_SENSOR_TYPE_MAX31875R0,
	TEMP_SENSOR_TYPE_MAX
};

typedef struct _temp_sensor {
	const char *name;
	int index;
	uint8_t  slave_address;
	uint8_t value_on;
	uint8_t value_off;
} temp_sensor_t;

static temp_sensor_t temp_sensor[TEMP_SENSOR_TYPE_MAX] = {
	{ "TMP310B",	TEMP_SENSOR_TYPE_TMP103B,	TMP103B_SLAVE_ADDRESS, 0x2, 0x0},
	{ "MAX31875R0",	TEMP_SENSOR_TYPE_MAX31875R0,	MAX31875R0_SLAVE_ADDRESS, 0x0, 0x1}
};

bool nrc_check_temp_sensor_exist(void);
bool nrc_get_temp_sensor_register(uint32_t id, uint8_t dev, uint8_t reg, int8_t *value);
bool nrc_set_temp_sensor_register(uint32_t id, uint8_t dev, uint8_t reg, int8_t value);
uint8_t nrc_get_temp_sensor_address(void);
uint8_t nrc_get_temp_sensor_value_on(void);
uint8_t nrc_get_temp_sensor_value_off(void);
int16_t nrc_calculate_temp_sensor_delta(void);
void nrc_temp_sensor_init(void);

#endif //__DRV_TEMP_SENSOR_H__

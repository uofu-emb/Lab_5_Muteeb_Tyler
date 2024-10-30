# Lab05 Realtime

- Muteeb Akram
- Tyler

### Jitter Measurement

Measurement is for the full toggle; ON->OFF->ON.

Expected Toggle time: 200ms

Number of toggle for 1hr time: 18,000


| Sleep Function | Mean Time (ms) | Mean Frequency | Mean Duty+ Cycle | Drift for 1hr|
|-------------|------------------|-------------|------------------|-------------|
| sleep.c | 202.415 | 4.9Hz | 50% | (202.415-200)*18000 ms = 43.47 sec |
| task_delay.c | 199.998 | 4.9997Hz | 50% | (216.415-200)*18000 ms = 295.47 sec |
| timer.c | 266.006 | 3.759Hz | 50% | (216.415-200)*18000 ms = 295.47 sec |


| Sleep Function | Mean Time (ms) | Mean Frequency | Mean Duty+ Cycle | Drift for 1hr|
|-------------|------------------|-------------|------------------|-------------|
| sleep.c | 216.608 | 4.648Hz | 50.01% | (216.415-200)*18000 ms = 295.47 sec |
| task_delay.c | 266.004 | 4.7593Hz | 50% | (266.004-200)*18000 ms = 1,188.072 sec |
| timer.c | 263.146 | 3.8145Hz | 50.01% | (263.146-200)*18000 ms = 1,136.628 sec |


### GPIO Jitter Measurement


Output Trigger Delay 18us
Average Delay Between Sync sign and Output 18us

Output Trigger Delay 7.65 ms
Average Delay Between Sync sign and Output 4.6800ms

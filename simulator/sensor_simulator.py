import random, time

DARK_THRESHOLD=1500
TEMP_ALERT_C=32.0
HUMIDITY_ALERT=80.0

relay=False
last_motion=time.time()

for step in range(20):
    temp=round(random.uniform(23,35),1)
    humidity=round(random.uniform(45,88),1)
    light=random.randint(300,3000)
    motion=random.choice([True,False])

    if motion: last_motion=time.time()
    if motion and light<DARK_THRESHOLD: relay=True
    if time.time()-last_motion>8: relay=False

    alerts=[]
    if temp>=TEMP_ALERT_C: alerts.append("HIGH_TEMP")
    if humidity>=HUMIDITY_ALERT: alerts.append("HIGH_HUMIDITY")

    print(f"[{step+1:02d}] temp={temp:4.1f}C humidity={humidity:4.1f}% "
          f"light={light:4d} motion={str(motion):5s} "
          f"relay={'ON ' if relay else 'OFF'} alerts={alerts or ['none']}")
    time.sleep(.5)

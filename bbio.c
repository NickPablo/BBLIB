#include "bbio.h"
#include "gperf_pinMap.h"
void pinDemo() {
    char buf[BUFSIZ];
    while (gets (buf)) {
       struct pin *p = getPin(buf, strlen (buf));
       if(p) printf ("ID = %s\ngpio = %i\nmux = %s\neeprom = %i\npwm = %s\n", p->ID, p->gpio, p->mux, p->eeprom, p->pwm);
       else printf("nope\n");
    }
}



void digitalWrite(const char *pin, int value) {
    char buf[29];
    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%i/value", getPin(pin, strlen(pin))->gpio);

    FILE *file = fopen(buf, "w");    

    if(value) fputc('1', file);
    else      fputc('0', file);

    fclose(file); 
    
}

int digitalRead(const char *pin) {    
    char buf[29];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%i/value", getPin(pin, strlen(pin))->gpio);


    FILE *file = fopen(buf, "r");

    char value = fgetc(file);

    fclose(file);

    if(value == '1') return 1;




    return 0;
}

void exportPin(const char *pin) {
    FILE *file = fopen("/sys/class/gpio/export", "w");   
    
    char num[3];    
    
    snprintf(num, sizeof(num), "%i", getPin(pin, strlen(pin))->gpio);    

    fputs(num, file);    

    fclose(file);
}

void unExport(const char *pin) {
    FILE *file = fopen("/sys/class/gpio/unexport", "w");
    char num[3];
    snprintf(num, sizeof(num), "%i", getPin(pin, strlen(pin))->gpio);

    fputs(num, file);

    fclose(file);
}

void digitalMode(const char *pin, int mode) {

    char buf[33];

    snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%i/direction", getPin(pin, strlen(pin))->gpio);

    FILE *file = fopen(buf, "w");

    if(mode) fputs("out", file);
    else     fputs("in", file);

    fclose(file);

}

long pulseIn(const char *pin, int value) {
    struct timeval tv;

    gettimeofday(&tv, NULL);
    double last, time = 0;

    puts("waiting for initial pulse...\n");
    gettimeofday(&tv, NULL);


    last = tv.tv_usec * 1000;

    while(1) {
        gettimeofday(&tv, NULL);
        double now = tv.tv_usec * 1000;
        if(abs(now - last) > 1000 * 1000)return -1;

        //cout << ".";
        if(digitalRead(pin) == value) {
            gettimeofday(&tv, NULL);

            last = tv.tv_usec;
            break;
        }
    }
    //cout <<endl;
    gettimeofday(&tv, NULL);
    double start = tv.tv_usec * 1000;

    puts("waiting for terminary pulse...\n");
    while(1) {
        gettimeofday(&tv, NULL);
        double now = tv.tv_usec;
        if(abs(now * 1000 - start) > 1000 * 1000)return -1;
        time += abs(last - now);
        last = now;


        //cout << ".";
        if(digitalRead(pin) != value) {
            gettimeofday(&tv, NULL);
            double now = tv.tv_usec;
            time += abs(last - now);

            break;
        }
    }
    // cout<<endl<<"done!"<<endl;

    return time;
}

void muxPin(const char* pin, int mode) {
    char buf[44];

    snprintf(buf, sizeof(buf), "/sys/kernel/debug/omap_mux/%s", getPin(pin, strlen(pin))->mux);
    FILE *file = fopen(buf, "w");
    
    fprintf(file, "%i", mode);
    
    fclose(file);
}

void pwmWrite(const char* pin, int frequency, int percent) {

}
}
import("stdfaust.lib");
/*process =
    dm.phaser2_demo; // stereo phaser*/

//process = 0,_~+(1):soundfile("sound[url:{'tango.wav'}]",2):!,!,_,_;
//process = 0,_~+(1):soundfile("sound[url:{ 'foo.wav' ;   'bara.wav'}]",2):!,!,_,_;

process = (waveform {10,20,30,40,50,60,70}, %(7)~+(3) : rdtable),
          (waveform {1.1,2.2,3.3,4.4,5.5,6.6,7.7}, %(7)~+(3) : rdtable);

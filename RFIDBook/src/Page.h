//
//  Page.h
//  RFIDBook
//
//  Created by Brett Peterson on 6/10/13.
//
//

#ifndef __RFIDBook__Page__
#define __RFIDBook__Page__

#include "ofMain.h"
#include "Media.h"
#include "BookView.h"
#include "ofxXmlSettings.h"
#include <iostream>

class BookView;

class Page {
    
public:
    Page();
    ~Page();
    
    void setup(); 
    void update();
    void dragUpdate();
    void draw(float originX, float originY, float scale);
    
    void addMedia(string fileName, ofVec2f position, int autoplay, string tapId, int loopback, bool _isHidden,int _offset);
    void addMedia(MediaModel _mm);
    
    bool isSegVid(string _fileName);
    
    void setDrag(bool _doDrag);
    
    void receiveInput(char touchId_in, int pageNum_in);
    
    void fade(int dir);
    
    vector<Media*> media;
    Media* selectedMedia;
    
    ofxXmlSettings getXML();
    
    void hideAllBorders();
    
    bool touchActive;
    bool pageReset;

    int activeMedia;
    int activePage;
    char currentTouch;
    
    // bullcrap
    vector<vector<int> > touchMediaMatrix;
    
    void printCurrentMedia();
    void printCurrentMediaByClassName(string _id);
    vector<Media *> getMediaByClassName(string _id);
    
    vector<Media *> getSegmentedMedia();
    
    BookView * viewRef;
    
    void registerView(BookView * _viewRef){
        viewRef = _viewRef;
    }
    
private:
    bool doDrag;
    
    int fadeOutMedia;
};

#endif /* defined(__RFIDBook__Page__) */

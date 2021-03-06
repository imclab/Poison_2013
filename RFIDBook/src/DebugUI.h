//
//  DebugUI.h
//  RFIDBook
//
//  Created by Cameron Browning on 6/14/13.
//
//

#ifndef __RFIDBook__DebugUI__
#define __RFIDBook__DebugUI__

#include "ofxSimpleGuiToo.h"
#include "ofMain.h"
#include "TextField.h"
#include "PositionUI.h"
#include "BarGraph.h"
#include "DeviceController.h"
#include "BookController.h"
#include "LanguageController.h"
#include "BookView.h"
#include "BookLoader.h"
#include "ofxQuadCrop.h"
#include "ofxQuadImage.h"
#include <iostream>

class DebugUI{
  
public:
    DebugUI();
    ~DebugUI();
    
    void setup(DeviceController * _devices, BookController * _book, LanguageController * _lang, BookView * _bookView, BookLoader *_loader, ofxQuadCrop * _cropper, ofxQuadImage * _quadImage);
    void update();
    void draw();
    
    void show();
    void hide();
    void toggle();
    
    bool getIsVisible();
    bool getDragSetting();
    void toggleFullScreen();
    
    bool toggleCursor();
     
private:
    BookView * bookView;
    bool bDragUIcheckbox;
    bool bDragUIcheckbox_prev;
    bool saveXMLbtn;
    bool loadXMLbtn;
    bool defaultXMLbtn;
    bool isVisible;
    bool bFullScreencheckbox;
    bool bFullScreencheckbox_prev;
    
    bool bQuadCropperEdit;
    bool bQuadCropperEdit_prev;
    bool loadCropBtn;
    bool saveCropBtn;
    
    bool bQuadImageEdit, bQuadImageEdit_prev;
    bool bLooseDrag, bLooseDrag_prev;
    bool loadQuadImageBtn;
    bool saveQuadImageBtn;
    
    DeviceController * devices;
    BookController * book;
    LanguageController * lang;
    BookLoader * loader;
    TextField tfield;
    PositionUI pos_ui;
    ofxQuadCrop * cropper;
    ofxQuadImage * quadImage;
    

    bool hideCursor();
    bool showCursor();
    bool bShowCursor;

};

#endif /* defined(__RFIDBook__DebugUI__) */

//
//  BookLoader.cpp
//  RFIDBook
//
//  Created by Brett Peterson on 6/18/13.
//
//

#include "BookLoader.h"

BookLoader::BookLoader(){}
BookLoader::~BookLoader(){}


// Load each page from the book XML file
vector< vector<MediaModel> > BookLoader::load(string fileName, LanguageController lang){
    
    cout << " -------- LOADING BOOK XML --------" << "\n";
    
    vector< vector<MediaModel> > allMedia;
    
    if (bookElements.loadFile(fileName)){
        
        pages.clear();
        
        bookElements.pushTag("Book");
        
        int numPages = bookElements.getNumTags("Page");
        ofLogNotice() << "Found " << numPages << " pages";
        
        for (int i = 0; i < numPages; i++){
            
            //XmlPage newPage;
            vector<MediaModel> thisPage;
            
            
            bookElements.pushTag("Page", i);
            
            int numMedia = bookElements.getNumTags("Media");
            ofLogNotice() << "loading " << numMedia << " media elements for page "<< i;
            
            for (int i=0; i<numMedia; i++){
                
                string mediaFileName;
                ofVec2f mediaPos;
                int autoplay = 0;
                string tapId;
                int loopback = 0;
                int pulse_int = 0;
                bool isHidden;
                ofBlendMode blend;
                int loopCount = 0;
                int flipMode_int;
                
                MediaModel thisMedia;
                
                int offset;
                
                mediaFileName = bookElements.getAttribute("Media", "src", "", i);
                offset = bookElements.getAttribute("Media", "offset", 0, i);
                
                // If file isn't found, preserve the file path to save back to the XML
                if (mediaFileName == "FILE NOT FOUND"){
                    mediaFileName = bookElements.getAttribute("Media", "src", "", i);
                }

                mediaPos.x = ofToFloat(bookElements.getAttribute("Media", "x", "0", i));
                mediaPos.y = ofToFloat(bookElements.getAttribute("Media", "y", "0", i));
                

                if (bookElements.attributeExists("Media", "auto", i)) {
                    // set autoplay to true
                    autoplay = ofToInt(bookElements.getAttribute("Media", "auto", "0", i));
                }
                if (bookElements.attributeExists("Media", "blend", i)) {
                    // set autoplay to true
                    blend = (ofBlendMode)bookElements.getAttribute("Media", "blend", 0, i);
                } else {
                    blend = OF_BLENDMODE_DISABLED;
                }
                
                
                if (bookElements.attributeExists("Media", "class", i)) {
                    tapId = bookElements.getAttribute("Media", "class", "0", i);
                }
                else {
                    tapId = "";
                }
                
                if (bookElements.attributeExists("Media", "loopback", i)) {
                    loopback = bookElements.getAttribute("Media", "loopback", 0, i);
                }
                else {
                    loopback = -1;
                }
                if (bookElements.attributeExists("Media", "loopcount", i)) {
                    loopCount = bookElements.getAttribute("Media", "loopcount", 0, i);
                }
                else {
                    loopCount = 0;
                }
                if (bookElements.attributeExists("Media", "pulse", i)) {
                    pulse_int = bookElements.getAttribute("Media", "pulse", 0, i);
                }
                else {
                    pulse_int = 0;
                }
                if (bookElements.attributeExists("Media", "hidden", i)) {
                    string hiddenString = bookElements.getAttribute("Media", "hidden", "0", i);
                    if(hiddenString.compare("1")==0 || hiddenString.compare("true")==0 || hiddenString.compare("yes")==0){
                        isHidden = true;
                    } else {
                        isHidden = false;
                    }
                    
                } else {
                    isHidden = false;
                }
                
                if (bookElements.attributeExists("Media", "flip", i)) {
                    flipMode_int = bookElements.getAttribute("Media", "flip", 0, i);
                } else {
                    flipMode_int = 0;
                }
                
                
                
                ofLogNotice() << "Loaded " << mediaFileName << " at position " << mediaPos.x << " : " << mediaPos.y;
                
                thisMedia.src = mediaFileName;
                thisMedia.pos = mediaPos;
                thisMedia.autoPlay = autoplay;
                thisMedia.mClass = tapId;
                thisMedia.loopback = loopback;
                thisMedia.isHidden = isHidden;
                thisMedia.offset = offset;
                thisMedia.pulseType = pulse_int;
                thisMedia.mediaType = -1;
                thisMedia.blend = blend;
                thisMedia.loopCount = loopCount;
                thisMedia.flip = flipMode_int;
                thisPage.push_back(thisMedia);
            }
            
            /////////////////
            
            // parsing touchvids
            
            //////////////////
            
            numMedia = bookElements.getNumTags("touchvid");
            
            for (int i=0; i<numMedia; i++){
                
                string mediaFileName;
                ofVec2f mediaPos;
                int autoplay = 0;
                string tapId;
                int loopback = 0;
                int pulse_int = 0;
                bool isHidden;
                ofBlendMode blend;
                int loopCount;
                
                MediaModel thisMedia;
                
                int offset;
                
                mediaFileName = bookElements.getAttribute("touchvid", "src", "", i);
                mediaPos.x = ofToFloat(bookElements.getAttribute("touchvid", "x", "0", i));
                mediaPos.y = ofToFloat(bookElements.getAttribute("touchvid", "y", "0", i));
                
                
                if (bookElements.attributeExists("touchvid", "class", i)) {
                    tapId = bookElements.getAttribute("touchvid", "class", "0", i);
                }
                else {
                    tapId = "";
                }
 
                if (bookElements.attributeExists("touchvid", "hidden", i)) {
                    string hiddenString = bookElements.getAttribute("Media", "hidden", "0", i);
                    if(hiddenString.compare("1")==0 || hiddenString.compare("true")==0 || hiddenString.compare("yes")==0){
                        isHidden = true;
                    } else {
                        isHidden = false;
                    }
                    
                } else {
                    isHidden = false;
                }
                if (bookElements.attributeExists("touchvid", "blend", i)) {
                    // set autoplay to true
                    blend = (ofBlendMode)bookElements.getAttribute("touchvid", "blend", 0, i);
                } else {
                    blend = OF_BLENDMODE_DISABLED;
                }
                loopCount = 0;
                if (bookElements.attributeExists("touchvid", "loopcount", i)) {
                    // set autoplay to true
                    loopCount = bookElements.getAttribute("touchvid", "loopcount", 0, i);
                } else {
                    loopCount = 0;
                }
                ofLogNotice() << "Loaded TOUCHVID: " << mediaFileName << " at position " << mediaPos.x << " : " << mediaPos.y;
               
                // build mediamodel for touchvid
                thisMedia.mediaType = 4;
                thisMedia.src = mediaFileName;
                thisMedia.pos = mediaPos;
                thisMedia.mClass = tapId;
                thisMedia.isHidden = isHidden;
                thisMedia.blend = blend;
                thisMedia.loopCount = loopCount;

                
                thisMedia.autoPlay = -1;
                thisMedia.offset = -1;
                thisMedia.pulseType = -1;
                thisMedia.loopback = -1;
                
                thisPage.push_back(thisMedia);
            }
            
            
            //////////////////
            
            bookElements.popTag();
            //pages.push_back(newPage);
            allMedia.push_back(thisPage);
        }
        

        
    }
    else {
        ofLogError() << "Book XML did not load properly";
    }
    
    cout << " ------------------------" << "\n";
    
    return allMedia;
}
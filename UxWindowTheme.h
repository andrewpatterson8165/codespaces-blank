#ifndef UXWINDOWTHEME_H_
#define UXWINDOWTHEME_H_

#include<uxtheme.h>

class UxWindowTheme : public Element
{
public:
    UxWindowTheme(Element* parent, string name);
    ~UxWindowTheme();
    UxWindowTheme(const UxWindowTheme& other);

//Properties
    void setPaintParams(BP_PAINTPARAMS* paintParams){_bpPainParamsProperties = paintParams;};
    void setDeviceContextTarget(HDC hdcTarget){ _drawContextTarget = hdcTarget;};
    void setTheme(HTHEME hTheme){ _themeHandle = hTheme;};
   
    void setStateId(int stateId){ _stateId = stateId;};
    void setPropertyId(int propertyId) { _propertyId = propertyId;};//TBD
    void setPartId(int partId){_partId = partId;};
    void setStoryBoardId(int iStoryboardId) { _storyBoardId;};
    void setTargetId(int iTargetId) { _targetId;};
    
    HANIMATIONBUFFER = beginBufferedAnimation(RECT* targetRect,
                                              BP_BUFFERFORMAT dwFormat,
                                              BP_ANIMATIONPARAMS* animationParams,//[IN]
                                              HDC* deviceContextFrom, //[OUT]
                                              HDC* deviceContextTo);// [OUT];
   
   HPAINTBUFFER beginBufferedPaint(const RECT  *prcTarget,
                                   BP_BUFFERFORMAT dwFormat,
                                   HDC *phdc); //Out
   

    BOOL beginPanningFeedback();
    HRESULT bufferedPainClear();
    HRESULT bufferedPaintInit();
    BOOL bufferedPaintRenderAnimation();
    HRESULT bufferedPaintSetAlpha(HPAINTBUFFER hBufferedPaint,
                                  const RECT *prc,
                                  BYTE alpha);
        
    HRESULT bufferedPaintStopAllAnimations();
    HRESULT bufferedPaintUnInit();
    HRESULT closeThemeData(HTHEME hTheme);

    HRESULT DrawThemeBackground(LPCRECT pRect,LPCRECT pClipRect);

    HRESULT drawThemeBackgroundEx(LPCRECT pRect,
                                  const DTBGOPTS *pOptions);
      
    HRESULT drawThemeEdge(LPCRECT pDestRect,
                          UINT    uEdge,
                          UINT    uFlags,
                          LPRECT  pContentRect);

    HRESULT drawThemeIcon(LPCRECT    pRect,
                          HIMAGELIST himl,
                          int  iImageIndex);


    HRESULT drawThemeParentBackground(const RECT *prc);


    HRESULT drawThemeParentBackgroundEx(DWORD dwFlags,
                                        const RECT *prc);

    HRESULT drawThemeText(LPCWSTR pszText,
                          int     cchText,
                          DWORD   dwTextFlags,
                          DWORD   dwTextFlags2,
                          LPCRECT pRect);    

    HRESULT drawThemeTextEx(LPCWSTR pszText,
                            int  cchText,
                            DWORD dwTextFlags,
                            LPRECT pRect, //In & out
                            const DTTOPTS *pOptions);

    HRESULT enableThemeDialogTexture(DWORD dwFlags);

    HRESULT enableTheming(BOOL fEnable);

    HRESULT endBufferedAnimation(HANIMATIONBUFFER hbpAnimation,
                                 BOOL fUpdateTarget);

      
    HRESULT endBufferedPaint(HPAINTBUFFER hBufferedPaint,
                             BOOL fUpdateTarget);

    BOOL endPanningFeedback(BOOL fAnimateBack);  

    HRESULT getBufferedPaintBits(HPAINTBUFFER hBufferedPaint,
                                 RGBQUAD **ppbBuffer,
                                 int *pcxRow);

    HDC getBufferedPaintDC(HPAINTBUFFER hBufferedPaint);
      
    HDC getBufferedPaintTargetDC(HPAINTBUFFER hBufferedPaint);   

    HRESULT getBufferedPaintTargetRect(HPAINTBUFFER hBufferedPaint,
                                       RECT  *prc);

    HRESULT getCurrentThemeName(LPWSTR pszThemeFileName,//out
                                int    cchMaxNameChars,//in
                                LPWSTR pszColorBuff, //out
                                int    cchMaxColorChars,//in
                                LPWSTR pszSizeBuff,//out
                                int    cchMaxSizeChars); //in

    HRESULT getThemeAnimationProperty(TA_PROPERTY eProperty,
                                      VOID  *pvProperty,//out
                                      DWORD cbSize, //in
                                      DWORD *pcbSizeOut); //out

    HRESULT GetThemeAnimationTransform(DWORD  dwTransformIndex, //in
                                       TA_TRANSFORM *pTransform, //out
                                       DWORD cbSize, //in
                                       DWORD *pcbSizeOut); //out

    HRESULT GetThemeBackgroundContentRect(LPCRECT pBoundingRect, LPRECT  pContentRect);
    
    HRESULT GetThemeBackgroundExtent(LPCRECT pContentRect,
                                     LPRECT  pExtentRect);

    HRESULT GetThemeBackgroundRegion(LPCRECT pRect, HRGN *pRegion);
      
    DWORD GetThemeAppProperties();

    HRESULT getThemeBitmap(ULONG   dwFlags, //in
                           HBITMAP *phBitmap);//out

    HRESULT getThemeBool(BOOL   *pfVal);

    HRESULT getThemeColor(COLORREF *pColor);

    HRESULT getThemeDocumentationProperty(LPCWSTR pszThemeName,
                                          LPCWSTR pszPropertyName,
                                          LPWSTR  pszValueBuff,//out
                                          int cchMaxValChars); //in

    HRESULT GetThemeEnumValue(int    *piVal);

    HRESULT GetThemeFilename(LPWSTR pszThemeFileName,
                             int  cchMaxBuffChars);

    HRESULT GetThemeFont(LOGFONTW *pFont);

    HRESULT GetThemeInt(int *piVal)

    HRESULT GetThemeIntList(INTLIST *pIntList);

    HRESULT GetThemeMargins(int iPropId,LPCRECT prc,MARGINS *pMargins);

    HRESULT GetThemeMetric(int iPropId,
                           int *piVal);
      
    HRESULT GetThemePartSize(LPCRECT prc,
                             THEMESIZE eSize,
                             SIZE *psz);

    HRESULT GetThemePosition(POINT *pPoint);

    HRESULT GetThemePropertyOrigin(PROPERTYORIGIN *pOrigin);

    HRESULT GetThemeRect(LPRECT pRect);

    HRESULT GetThemeStream(VOID **ppvStream,
                           DWORD *pcbStream,
                           HINSTANCE hInst);

    HRESULT GetThemeString(int iPropId, LPWSTR pszBuff, int cchMaxBuffChars);
      
    BOOL getThemeSysBool(int iBoolId);

    COLORREF getThemeSysColor(int iColorId);     

    HBRUSH getThemeSysColorBrush(int iColorId);

    HRESULT getThemeSysFont(int iFontId, LOGFONTW *plf);

    HRESULT getThemeSysInt(int iIntId, int *piValue);

    int getThemeSysSize(int  iSizeId);      

    HRESULT getThemeSysString(int iStringId,
                              LPWSTR pszStringBuff,//
                              int cchMaxStringChars);

    HRESULT getThemeTextExtent(LPCWSTR pszText,//in
                               int     cchCharCount,//in
                               DWORD   dwTextFlags,//in
                               LPCRECT pBoundingRect, //in
                               LPRECT  pExtentRect); //out

    HRESULT getThemeTextMetrics(TEXTMETRICW *ptm);//[out param]
      
    HRESULT GetThemeTimingFunction(int  iTimingFunctionId,
                                   TA_TIMINGFUNCTION *pTimingFunction,//out
                                   DWORD cbSize,
                                   DWORD *pcbSizeOut);

    HRESULT GetThemeTransitionDuration(int iStateIdFrom,
                                       int iStateIdTo,
                                       DWORD  *pdwDuration); //out 

    HTHEME getWindowTheme();
      
    HRESULT HitTestThemeBackground(DWORD dwOptions,
                                   LPCRECT pRect,
                                   HRGN hrgn,
                                   POINT ptTest,
                                   WORD *pwHitTestCode);  

    bool IsAppThemed();
    bool IsCompositionActive();
    bool IsThemeActive();
      
    bool IsThemeBackgroundPartiallyTransparent();

    bool IsThemeDialogTextureEnabled();
      
    bool IsThemePartDefined();

    HTHEME openThemeDataEx(LPCWSTR pszClassList,
                           DWORD   dwFlags);     

    HTHEME openThemeDataForDpi(LPCWSTR pszClassList,UINT dpi);

    void setThemeAppProperties(DWORD dwFlags);

    HRESULT SetWindowThemeAttribute(WINDOWTHEMEATTRIBUTETYPE eAttribute,
                                    PVOID pvAttribute,
                                    DWORD cbAttribute);

    HRESULT SetWindowThemeNonClientAttributes(DWORD dwMask,DWORD dwAttributes);
      
protected:  
    HDC _drawContextTarget;
    HTHEME _themeHandle;  
    INT _stateId;
    INT _propertyId;
    INT _partId;
    int _storyBoardId;
private:
    //Defines animation parameters for the BP_PAINTPARAMS structure used by BeginBufferedPaint.
    BP_ANIMATIONPARAMS _bpAnimationParamsProperties;

    //Defines paint operation parameters for BeginBufferedPaint.
    BP_PAINTPARAMS _bpPaintParamsProperties;

    //Defines the options for the DrawThemeBackgroundEx function.
    DTBGOPTS  _dtbgoptsProperties;

    //Defines the options for the DrawThemeTextEx function.
    DTTOPTS _dttoptsProperties;

    //Contains an array or list of int data items from a visual style.
    INTLIST _intListProperties;

    //Returned by the GetThemeMargins function to define the margins of windows that have visual styles applied.
    MARGINS _marginsProperties

    //Defines options that are used to set window visual style attributes.
    WTA_OPTIONS _wtaOptionsProperties;

    BP_ANIMATIONSTYLE _bpAnimationStyleEnum;
    BP_BUFFERFORMAT  _bpBufferFormatEnum;
    PROPERTYORIGIN  _propertyOriginEnum;
    THEMESIZE _themeSizeEnum;
    WINDOWTHEMEATTRIBUTETYPE _windowThemeAttributeEnum;
};

#endif

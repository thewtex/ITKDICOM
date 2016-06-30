/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkDICOMImage_h
#define itkDICOMImage_h

#include "itkImage.h"

namespace itk
{
/** \class DICOMImage
 *  \brief Templated n-dimensional image class.
 *
 * Images are templated over a pixel type (modeling the dependent
 * variables), and a dimension (number of independent variables).  The
 * container for the pixel data is the ImportImageContainer.
 *
 * Within the pixel container, images are modelled as arrays, defined by a
 * start index and a size.
 *
 * The superclass of Image, ImageBase, defines the geometry of the
 * image in terms of where the image sits in physical space, how the
 * image is oriented in physical space, the size of a pixel, and the
 * extent of the image itself.  ImageBase provides the methods to
 * convert between the index and physical space coordinate frames.
 *
 * Pixels can be accessed direcly using the SetPixel() and GetPixel()
 * methods or can be accessed via iterators that define the region of
 * the image they traverse.
 *
 * The pixel type may be one of the native types; a Insight-defined
 * class type such as Vector; or a user-defined type. Note that
 * depending on the type of pixel that you use, the process objects
 * (i.e., those filters processing data objects) may not operate on
 * the image and/or pixel type. This becomes apparent at compile-time
 * because operator overloading (for the pixel type) is not supported.
 *
 * The data in an image is arranged in a 1D array as [][][][slice][row][col]
 * with the column index varying most rapidly.  The Index type reverses
 * the order so that with Index[0] = col, Index[1] = row, Index[2] = slice,
 * ...
 *
 * \sa ImageBase
 * \sa ImageContainerInterface
 *
 * \ingroup ImageObjects
 * \ingroup DICOM
 *
 * \wiki
 * \wikiexample{SimpleOperations/SetPixels,Set specified pixels to specified values}
 * \endwiki
 */
template< typename TPixel, unsigned int VImageDimension = 3 >
class DICOMImage:public Image< TPixel, VImageDimension >
{
public:
  /** Standard class typedefs */
  typedef DICOMImage                       Self;
  typedef Image< TPixel, VImageDimension > Superclass;
  typedef SmartPointer< Self >             Pointer;
  typedef SmartPointer< const Self >       ConstPointer;
  typedef WeakPointer< const Self >        ConstWeakPointer;

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(DICOMImage, Image);

  /** Pixel typedef support. Used to declare pixel type in filters
   * or other operations. */
  typedef TPixel PixelType;

  /** Typedef alias for PixelType */
  typedef TPixel ValueType;

  /** Internal Pixel representation. Used to maintain a uniform API
   * with Image Adaptors and allow to keep a particular internal
   * representation of data while showing a different external
   * representation. */
  typedef typename Superclass::InternalPixelType InternalPixelType;

  typedef typename Superclass::IOPixelType IOPixelType;

  /** Accessor type that convert data between internal and external
   *  representations.  */
  typedef typename Superclass::AccessorType        AccessorType;
  typedef typename Superclass::AccessorFunctorType AccessorFunctorType;

  /** Typedef for the functor used to access a neighborhood of pixel
   * pointers. */
  typedef typename Superclass::NeighborhoodAccessorFunctorType NeighborhoodAccessorFunctorType;

  /** Type of image dimension */
  typedef typename Superclass::ImageDimensionType ImageDimensionType;

  /** Index typedef support. An index is used to access pixel values. */
  typedef typename Superclass::IndexType      IndexType;
  typedef typename Superclass::IndexValueType IndexValueType;

  /** Offset typedef support. An offset is used to access pixel values. */
  typedef typename Superclass::OffsetType OffsetType;

  /** Size typedef support. A size is used to define region bounds. */
  typedef typename Superclass::SizeType      SizeType;
  typedef typename Superclass::SizeValueType SizeValueType;

  /** Container used to store pixels in the image. */
  typedef typename Superclass::PixelContainer PixelContainer;

  /** Direction typedef support. A matrix of direction cosines. */
  typedef typename Superclass::DirectionType DirectionType;

  /** Region typedef support. A region is used to specify a subset of an image.
    */
  typedef typename Superclass::RegionType RegionType;

  /** Spacing typedef support.  Spacing holds the size of a pixel.  The
   * spacing is the geometric distance between image samples. */
  typedef typename Superclass::SpacingType      SpacingType;
  typedef typename Superclass::SpacingValueType SpacingValueType;

  /** Origin typedef support.  The origin is the geometric coordinates
   * of the index (0,0). */
  typedef typename Superclass::PointType PointType;

  /** A pointer to the pixel container. */
  typedef typename Superclass::PixelContainerPointer      PixelContainerPointer;
  typedef typename Superclass::PixelContainerConstPointer PixelContainerConstPointer;

  /** Offset typedef (relative position between indices) */
  typedef typename Superclass::OffsetValueType OffsetValueType;

protected:
  DICOMImage();
  void PrintSelf(std::ostream & os, Indent indent) const ITK_OVERRIDE;

  virtual ~DICOMImage() {}

private:
  ITK_DISALLOW_COPY_AND_ASSIGN(DICOMImage);
};
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkDICOMImage.hxx"
#endif

#endif

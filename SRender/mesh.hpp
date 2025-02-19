#pragma once
#include <vector>
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

#ifndef _NODISCARD
#define _NODISCARD [[nodiscard]]
#endif

namespace srender
{
/** A mesh is a collection of vertices used to draw shapes. */
struct mesh
{
	struct vertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texCoords;
	};

private:
	uint32_t m_idVAO = 0U;	// The id for the vertex attribute object
	uint32_t m_idVBO = 0U;	// The id for the vertex buffer object
	uint32_t m_idEBO = 0U;	// The id for the element buffer object

	std::vector<vertex> *m_vertices = nullptr;
	std::vector<uint32_t> *m_indices = nullptr;
	uint32_t m_count;

public:
	/** Takes the vertices array and places it in a vector.
	 * @return [std::vector<Vertex>] The vertex vector.
	 */
	_NODISCARD static std::vector<vertex> generateVertices() noexcept;

	/** Takes the indices array and places it in a vector.
	 * @return [std::vector<uint32_t>] The indices vector.
	 */
	_NODISCARD static std::vector<uint32_t> generateIndices() noexcept;

	/** Creates a mesh object
	 * @param _vertices Vertex data to be used, should be on the heap
	 * @param _indices Index data to be used, should be on the heap
	 * @param _save Whether the vertex and index data is saved to the Mesh object
	 */
	mesh(
		std::vector<vertex> *_vertices,
		std::vector<uint32_t> *_indices,
		bool _save = false
	) noexcept;
	~mesh();

	void draw() const noexcept;

	/** Get the id for the vertex attribute object.
	 * @return [uint32_t] The id of the vertex attribute object.
	 */
	_NODISCARD uint32_t getVAO() const noexcept;
	/** Get the id for the vertex buffer object.
	 * @return [uint32_t] The id of the vertex buffer object.
	 */
	_NODISCARD uint32_t getVBO() const noexcept;
	/** Get the id for the element buffer object.
	 * @return [uint32_t] The id of the element buffer object.
	 */
	_NODISCARD uint32_t getEBO() const noexcept;
};
}

using DHT.Database;
using DHT.Models;
using Microsoft.AspNetCore.Mvc;

namespace DHT.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class DHTDataController : ControllerBase
    {
        private readonly DHTDataContext _context;

        public DHTDataController(DHTDataContext context)
        {
            _context = context;
        }

        [HttpPost]
        public async Task<IActionResult> StoreData([FromBody] DHTData data)
        {
            data.Id = Guid.NewGuid();
            data.Timestamp = DateTime.UtcNow;
            data.Location = "Lebanon - Tripoli";
            _context.DHTDatas.Add(data);
            await _context.SaveChangesAsync();
            return Ok();
        }

        [HttpGet]
        public IActionResult GetData()
        {
            var data = _context.DHTDatas.ToList();
            return Ok(data);
        }
        
        //one way to get last data
        [HttpGet("last")]
        public IActionResult GetLastData()
        {
            var data = _context.DHTDatas.OrderByDescending(x => x.Timestamp).FirstOrDefault();
            return Ok(data);
        }
    }
}
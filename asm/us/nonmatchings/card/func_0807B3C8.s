.syntax unified
	.align 2, 0
	.global func_0807B3C8
	.thumb
	.thumb_func
	.type func_0807B3C8, %function
func_0807B3C8: @ 0807B3C8
	ldr r0, _0807B3D4 @ =0x02039DD4
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _0807B3D8
	movs r0, #0xFF
	b _0807B3DC
_0807B3D4: .4byte 0x02039DD4
_0807B3D8:
	adds r0, #0xD2
	ldrb r0, [r0, #0x00]
_0807B3DC:
	bx lr
	.byte 0x00, 0x00
.syntax divided

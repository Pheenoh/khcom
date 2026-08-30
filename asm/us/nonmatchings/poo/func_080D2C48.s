.syntax unified
	.align 2, 0
	.global func_080D2C48
	.thumb
	.thumb_func
	.type func_080D2C48, %function
func_080D2C48: @ 080D2C48
	push {lr}
	bl func_080D2BE0
	ldr r1, _080D2C68 @ =0x0203C470
	movs r0, #0x00
	strh r0, [r1, #0x28]
	movs r2, #0x03
	strh r2, [r1, #0x3C]
	ldr r3, _080D2C6C @ =0x0000073B
	strh r3, [r1, #0x3E]
	ldr r0, _080D2C70 @ =0x0203C3E4
	strh r2, [r0, #0x00]
	ldr r0, _080D2C74 @ =0x0203C3E0
	strh r3, [r0, #0x00]
	pop {r0}
	bx r0
_080D2C68: .4byte 0x0203C470
_080D2C6C: .4byte 0x0000073B
_080D2C70: .4byte 0x0203C3E4
_080D2C74: .4byte 0x0203C3E0
.syntax divided

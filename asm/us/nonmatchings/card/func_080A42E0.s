.syntax unified
	.align 2, 0
	.global func_080A42E0
	.thumb
	.thumb_func
	.type func_080A42E0, %function
func_080A42E0: @ 080A42E0
	push {lr}
	ldr r0, _080A42F4 @ =0x02034AFC
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080A42F8
	bl func_080A4DAC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080A4302
_080A42F4: .4byte 0x02034AFC
_080A42F8:
	ldr r2, _080A4308 @ =0x0000014F
	adds r1, r0, r2
	movs r0, #0x00
	strb r0, [r1, #0x00]
	movs r0, #0x01
_080A4302:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080A4308: .4byte 0x0000014F
.syntax divided

.syntax unified
	.align 2, 0
	.global func_080A9968
	.thumb
	.thumb_func
	.type func_080A9968, %function
func_080A9968: @ 080A9968
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r1, _080A9998 @ =0x0000063C
	adds r0, r5, r1
	bl func_08000C8C
	cmp r0, #0x00
	beq _080A998A
	movs r4, #0x01
_080A997A:
	adds r1, r0, #0x0
	adds r1, #0x4A
	strb r4, [r1, #0x00]
	adds r0, #0x2C
	bl func_08000CD4
	cmp r0, #0x00
	bne _080A997A
_080A998A:
	ldr r1, _080A999C @ =0x00000614
	adds r0, r5, r1
	bl TaskPoolUpdate
	pop {r4, r5}
	pop {r0}
	bx r0
_080A9998: .4byte 0x0000063C
_080A999C: .4byte 0x00000614
.syntax divided

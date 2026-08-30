.syntax unified
	.align 2, 0
	.global func_080BB43C
	.thumb
	.thumb_func
	.type func_080BB43C, %function
func_080BB43C: @ 080BB43C
	push {r4, lr}
	adds r4, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [r4, #0x08]
	cmp r0, r1
	beq _080BB45C
	str r1, [r4, #0x08]
	movs r0, #0x00
	strh r0, [r4, #0x00]
	strh r0, [r4, #0x02]
	strh r2, [r4, #0x04]
	adds r1, #0x04
	adds r0, r3, #0x0
	bl func_080BB428
_080BB45C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

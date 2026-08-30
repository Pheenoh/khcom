.syntax unified
	.align 2, 0
	.global func_080DD9B0
	.thumb
	.thumb_func
	.type func_080DD9B0, %function
func_080DD9B0: @ 080DD9B0
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r5, #0x00
	b _080DD9D8
_080DD9B8:
	lsls r1, r5, #0x02
	adds r0, r6, #0x0
	adds r0, #0x18
	adds r4, r0, r1
	ldr r0, [r4, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080DD9D4
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x04]
	bl func_080DDD30
_080DD9D4:
	adds r5, #0x01
	adds r0, r6, #0x0
_080DD9D8:
	adds r0, #0x40
	ldrh r0, [r0, #0x00]
	cmp r5, r0
	blt _080DD9B8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

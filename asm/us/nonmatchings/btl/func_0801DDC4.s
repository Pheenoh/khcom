.syntax unified
	.align 2, 0
	.global func_0801DDC4
	.thumb
	.thumb_func
	.type func_0801DDC4, %function
func_0801DDC4: @ 0801DDC4
	push {lr}
	adds r2, r0, #0x0
	movs r1, #0xB9
	lsls r1, r1, #0x01
	adds r0, r2, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0801DDDE
	ldr r0, [r2, #0x44]
	ldr r1, [r2, #0x48]
	ldr r2, [r2, #0x4C]
	bl func_0802F284
_0801DDDE:
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

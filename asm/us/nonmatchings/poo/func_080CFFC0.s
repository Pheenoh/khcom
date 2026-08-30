.syntax unified
	.align 2, 0
	.global func_080CFFC0
	.thumb
	.thumb_func
	.type func_080CFFC0, %function
func_080CFFC0: @ 080CFFC0
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, [r4, #0x00]
	ldr r1, [r5, #0x00]
	ldr r2, _080CFFE8 @ =0xFFFFBA00
	adds r0, r0, r2
	lsls r1, r1, #0x01
	subs r0, r0, r1
	movs r1, #0x05
	bl __divsi3
	str r0, [r4, #0x00]
	lsls r0, r0, #0x01
	ldr r1, _080CFFEC @ =0xFFFFDD00
	subs r1, r1, r0
	str r1, [r5, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_080CFFE8: .4byte 0xFFFFBA00
_080CFFEC: .4byte 0xFFFFDD00
.syntax divided

.syntax unified
	.align 2, 0
	.global func_0801AF1C
	.thumb
	.thumb_func
	.type func_0801AF1C, %function
func_0801AF1C: @ 0801AF1C
	push {r4, lr}
	ldr r1, _0801AF3C @ =0x02039B84
	ldr r1, [r1, #0x00]
	adds r3, r1, #0x0
	adds r3, #0xD0
	adds r1, #0xD8
	movs r4, #0x00
	ldsh r2, [r1, r4]
	lsls r2, r2, #0x08
	ldr r1, [r3, #0x00]
	adds r1, r1, r2
	cmp r0, r1
	blt _0801AF40
	movs r0, #0x80
	lsls r0, r0, #0x03
	b _0801AF44
_0801AF3C: .4byte 0x02039B84
_0801AF40:
	movs r0, #0x80
	lsls r0, r0, #0x04
_0801AF44:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided

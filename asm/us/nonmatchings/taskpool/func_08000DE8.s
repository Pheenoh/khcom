.syntax unified
	.align 2, 0
	.global func_08000DE8
	.thumb
	.thumb_func
	.type func_08000DE8, %function
func_08000DE8: @ 08000DE8
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r1, #0x0
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x10]
	cmp r1, #0x00
	beq _08000DFC
	ldr r0, [r4, #0x04]
	bl _call_via_r1
_08000DFC:
	ldr r0, [r4, #0x04]
	bl EwramFree
	adds r0, r4, #0x0
	adds r0, #0x0C
	adds r1, r5, #0x0
	bl func_08000C54
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

.syntax unified
	.align 2, 0
	.global func_08000EE0
	.thumb
	.thumb_func
	.type func_08000EE0, %function
func_08000EE0: @ 08000EE0
	push {r4, lr}
	bl func_08000C8C
	b _08000EFE
_08000EE8:
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x0C]
	cmp r1, #0x00
	beq _08000EF6
	ldr r0, [r4, #0x04]
	bl _0811D5B4
_08000EF6:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08000CD4
_08000EFE:
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _08000EE8
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided

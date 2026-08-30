.syntax unified
	.align 2, 0
	.global func_08000EA4
	.thumb
	.thumb_func
	.type func_08000EA4, %function
func_08000EA4: @ 08000EA4
	push {r4, r5, lr}
	adds r5, r0, #0x0
	bl func_08000C8C
	b _08000ED4
_08000EAE:
	ldr r2, [r4, #0x20]
	cmp r2, #0x00
	beq _08000ECC
	ldr r0, [r4, #0x04]
	adds r1, r4, #0x0
	bl _0811D5B8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _08000ECC
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl func_08000DBC
	b _08000ED4
_08000ECC:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08000CD4
_08000ED4:
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _08000EAE
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided

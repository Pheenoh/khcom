.syntax unified
	.align 2, 0
	.global func_08111678
	.thumb
	.thumb_func
	.type func_08111678, %function
func_08111678: @ 08111678
	push {r4, lr}
	add sp, #-0x018
	adds r2, r0, #0x0
	movs r1, #0x00
	ldr r0, [r2, #0x04]
	cmp r0, #0x00
	beq _0811168A
	movs r0, #0x00
	b _081116BE
_0811168A:
	ldr r3, [r2, #0x0C]
	movs r4, #0x00
	ldsh r0, [r3, r4]
	cmp r0, #0x1F
	bgt _081116BC
	str r1, [sp, #0x000]
	ldr r0, [r2, #0x30]
	str r0, [sp, #0x004]
	ldr r0, [r2, #0x34]
	str r0, [sp, #0x008]
	ldr r0, [r2, #0x38]
	str r0, [sp, #0x00C]
	mov r1, sp
	ldr r0, [r2, #0x08]
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x12]
	str r3, [sp, #0x014]
	ldr r0, _081116C8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	ldr r1, _081116CC @ =0x09EF9F0C
	mov r2, sp
	bl TaskCreate
	movs r1, #0x01
_081116BC:
	adds r0, r1, #0x0
_081116BE:
	add sp, #0x018
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_081116C8: .4byte 0x02039B84
_081116CC: .4byte 0x09EF9F0C
.syntax divided

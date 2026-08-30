.syntax unified
	.align 2, 0
	.global func_081108AC
	.thumb
	.thumb_func
	.type func_081108AC, %function
func_081108AC: @ 081108AC
	push {r4, r5, lr}
	add sp, #-0x018
	adds r2, r0, #0x0
	adds r4, r1, #0x0
	movs r3, #0x00
	movs r1, #0x0E
	ldsh r0, [r2, r1]
	cmp r0, #0x00
	beq _081108C2
	movs r0, #0x00
	b _08110908
_081108C2:
	ldr r0, [r2, #0x20]
	movs r5, #0x00
	ldsh r1, [r0, r5]
	adds r5, r0, #0x0
	cmp r1, #0x1F
	bgt _08110906
	str r3, [sp, #0x000]
	cmp r4, #0x01
	bne _081108E0
	ldr r0, [r2, #0x50]
	str r0, [sp, #0x004]
	ldr r0, [r2, #0x54]
	str r0, [sp, #0x008]
	ldr r0, [r2, #0x58]
	b _081108EA
_081108E0:
	ldr r0, [r2, #0x28]
	str r0, [sp, #0x004]
	ldr r0, [r2, #0x2C]
	str r0, [sp, #0x008]
	ldr r0, [r2, #0x30]
_081108EA:
	str r0, [sp, #0x00C]
	mov r1, sp
	ldr r0, [r2, #0x1C]
	ldrh r0, [r0, #0x00]
	strh r0, [r1, #0x12]
	str r5, [sp, #0x014]
	ldr r0, _08110910 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x40
	ldr r1, _08110914 @ =0x09EF9F0C
	mov r2, sp
	bl func_08000E14
	movs r3, #0x01
_08110906:
	adds r0, r3, #0x0
_08110908:
	add sp, #0x018
	pop {r4, r5}
	pop {r1}
	bx r1
_08110910: .4byte 0x02039B84
_08110914: .4byte 0x09EF9F0C
.syntax divided

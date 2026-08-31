.syntax unified
	.align 2, 0
	.global task_bos_md_1
	.thumb
	.thumb_func
	.type task_bos_md_1, %function
task_bos_md_1: @ 080FC6D4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x02C
	adds r7, r0, #0x0
	movs r0, #0x01
	str r0, [sp, #0x008]
	adds r0, r7, #0x0
	bl _080FC360
	ldr r0, [r7, #0x00]
	cmp r0, #0x04
	bhi _080FC740
	lsls r0, r0, #0x02
	ldr r1, _080FC6FC @ =0x080FC700
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	mov pc, r0
_080FC6FC: .4byte 0x080FC700
	.byte 0x14, 0xC7, 0x0F, 0x08, 0x1C, 0xC7, 0x0F, 0x08, 0x24, 0xC7, 0x0F, 0x08, 0x2C, 0xC7, 0x0F, 0x08
	.byte 0x34, 0xC7, 0x0F, 0x08, 0x38, 0x1C, 0xFF, 0xF7, 0xCF, 0xF9, 0x0E, 0xE0, 0x38, 0x1C, 0xFF, 0xF7
	.byte 0x95, 0xFA, 0x0A, 0xE0, 0x38, 0x1C, 0xFF, 0xF7, 0x55, 0xFB, 0x06, 0xE0, 0x38, 0x1C, 0xFF, 0xF7
	.byte 0x3B, 0xFC, 0x02, 0xE0, 0x38, 0x1C, 0xFF, 0xF7, 0x21, 0xFD, 0x00, 0x06, 0x00, 0x0E, 0x02, 0x90
_080FC740:
	adds r0, r7, #0x0
	bl func_080FC3FC
	movs r0, #0x00
	bl func_0801C1C0
	lsls r0, r0, #0x18
	adds r1, r7, #0x0
	adds r1, #0x54
	str r1, [sp, #0x014]
	adds r2, r7, #0x0
	adds r2, #0x40
	str r2, [sp, #0x010]
	cmp r0, #0x00
	beq _080FC772
	str r1, [sp, #0x000]
	movs r5, #0xDA
	lsls r5, r5, #0x01
	adds r0, r7, r5
	str r0, [sp, #0x004]
	ldr r1, _080FC8A4 @ =0x09EF8EF4
	adds r0, r2, #0x0
	mov r2, sp
	bl TaskCreate
_080FC772:
	adds r0, r7, #0x0
	bl func_080FBA4C
	ldrh r1, [r7, #0x1A]
	movs r6, #0x1A
	ldsh r0, [r7, r6]
	cmp r0, #0x00
	ble _080FC786
	subs r0, r1, #0x1
	strh r0, [r7, #0x1A]
_080FC786:
	movs r0, #0x00
	adds r1, r7, #0x0
	adds r1, #0x6C
	str r1, [sp, #0x018]
	adds r2, r7, #0x0
	adds r2, #0x70
	str r2, [sp, #0x01C]
	adds r5, r7, #0x0
	adds r5, #0x74
	str r5, [sp, #0x020]
	adds r6, r7, #0x0
	adds r6, #0x2C
	str r6, [sp, #0x024]
	movs r1, #0xD7
	lsls r1, r1, #0x01
	adds r1, r7, r1
	str r1, [sp, #0x00C]
	movs r2, #0xD4
	lsls r2, r2, #0x01
	adds r2, r2, r7
	mov r10, r2
_080FC7B0:
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r0, r4, #0x04
	adds r0, r0, r4
	lsls r0, r0, #0x04
	ldr r5, [sp, #0x018]
	adds r5, r5, r0
	mov r9, r5
	ldr r1, _080FC8A8 @ =0x02039B84
	ldr r1, [r1, #0x00]
	mov r12, r1
	mov r5, r12
	adds r5, #0xCC
	lsls r3, r4, #0x03
	ldr r6, [sp, #0x00C]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	mov r6, r10
	ldr r2, [r6, #0x00]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r6, #0x4C
	muls r1, r6
	adds r1, r3, r1
	ldr r2, _080FC8AC @ =0x09992108
	adds r1, r1, r2
	adds r1, #0x44
	movs r6, #0x00
	ldsh r2, [r1, r6]
	lsls r2, r2, #0x08
	ldr r1, [r5, #0x00]
	adds r1, r1, r2
	mov r2, r9
	str r1, [r2, #0x00]
	ldr r5, [sp, #0x01C]
	adds r5, r5, r0
	mov r8, r5
	mov r5, r12
	adds r5, #0xD0
	ldr r6, [sp, #0x00C]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	mov r6, r10
	ldr r2, [r6, #0x00]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r6, #0x4C
	muls r1, r6
	adds r1, r3, r1
	ldr r2, _080FC8AC @ =0x09992108
	adds r1, r1, r2
	adds r1, #0x46
	movs r6, #0x00
	ldsh r2, [r1, r6]
	lsls r2, r2, #0x08
	ldr r1, [r5, #0x00]
	adds r1, r1, r2
	mov r2, r8
	str r1, [r2, #0x00]
	ldr r5, [sp, #0x020]
	adds r5, r5, r0
	str r5, [sp, #0x028]
	mov r5, r12
	adds r5, #0xD4
	ldr r6, [sp, #0x00C]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	mov r6, r10
	ldr r2, [r6, #0x00]
	lsls r1, r1, #0x02
	adds r1, r1, r2
	movs r2, #0x00
	ldsh r1, [r1, r2]
	movs r6, #0x4C
	muls r1, r6
	adds r3, r3, r1
	ldr r1, _080FC8AC @ =0x09992108
	adds r3, r3, r1
	adds r3, #0x48
	movs r2, #0x00
	ldsh r1, [r3, r2]
	lsls r1, r1, #0x08
	ldr r3, [r5, #0x00]
	adds r3, r3, r1
	ldr r5, [sp, #0x028]
	str r3, [r5, #0x00]
	adds r0, r0, r7
	adds r0, #0xA8
	mov r6, r9
	ldr r1, [r6, #0x00]
	mov r5, r8
	ldr r2, [r5, #0x00]
	bl func_08012324
	adds r4, #0x01
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	cmp r4, #0x00
	ble _080FC7B0
	ldr r0, [sp, #0x024]
	bl TaskPoolUpdate
	ldr r0, [sp, #0x010]
	bl TaskPoolUpdate
	ldr r0, [sp, #0x014]
	bl TaskPoolUpdate
	ldr r0, [sp, #0x008]
	add sp, #0x02C
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080FC8A4: .4byte 0x09EF8EF4
_080FC8A8: .4byte 0x02039B84
_080FC8AC: .4byte 0x09992108
.syntax divided

.syntax unified
	.align 2, 0
	.global task_poo_shadowdodai_2
	.thumb
	.thumb_func
	.type task_poo_shadowdodai_2, %function
task_poo_shadowdodai_2: @ 080CBFDC
	push {r4, r5, r6, lr}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r2, [r6, #0x18]
	ldrh r0, [r2, #0x00]
	cmp r0, #0x00
	beq _080CC052
	ldr r4, [r2, #0x04]
	ldr r0, [r6, #0x14]
	ldr r1, [r0, #0x08]
	cmp r1, r4
	blt _080CBFF8
	movs r2, #0xA6
	b _080CC00C
_080CBFF8:
	subs r1, r4, r1
	cmp r1, #0x00
	bge _080CC000
	adds r1, #0x7F
_080CC000:
	asrs r1, r1, #0x07
	movs r0, #0xA6
	subs r2, r0, r1
	cmp r2, #0x18
	bgt _080CC00C
	movs r2, #0x19
_080CC00C:
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x00
	bl AllocObjAffine
	adds r5, r0, #0x0
	ldr r0, [r6, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _080CC05C @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	ldr r1, [r6, #0x04]
	asrs r1, r1, #0x08
	asrs r2, r4, #0x08
	adds r1, r1, r2
	ldr r2, _080CC060 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r6, #0x10]
	ldr r3, [r6, #0x08]
	ldr r4, [r6, #0x0C]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r4, [r6, #0x18]
	ldrh r4, [r4, #0x00]
	str r4, [sp, #0x00C]
	bl DrawSprite
_080CC052:
	add sp, #0x010
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CC05C: .4byte 0x0203C40C
_080CC060: .4byte 0x0203C3F8
.syntax divided

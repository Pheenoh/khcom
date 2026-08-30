.syntax unified
	.align 2, 0
	.global task_poo_owl_2
	.thumb
	.thumb_func
	.type task_poo_owl_2, %function
task_poo_owl_2: @ 080CE1D8
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r0, #0x34
	bl func_08000EE0
	ldr r2, [r4, #0x24]
	asrs r2, r2, #0x08
	ldr r0, _080CE238 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r2, r2, r0
	ldr r1, [r4, #0x28]
	asrs r1, r1, #0x08
	ldr r0, [r4, #0x2C]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080CE23C @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r2, r2, #0x10
	asrs r7, r2, #0x10
	lsls r1, r1, #0x10
	asrs r6, r1, #0x10
	movs r0, #0x08
	str r0, [sp, #0x000]
	str r0, [sp, #0x004]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	movs r2, #0x18
	movs r3, #0x08
	bl func_080035CC
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	beq _080CE240
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	beq _080CE28C
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	movs r0, #0x00
	str r0, [r4, #0x04]
	b _080CE28C
_080CE238: .4byte 0x0203C40C
_080CE23C: .4byte 0x0203C3F8
_080CE240:
	ldr r0, [r4, #0x04]
	cmp r0, #0x00
	bne _080CE25E
	adds r0, r4, #0x0
	adds r0, #0x4C
	ldrh r0, [r0, #0x00]
	ldr r1, _080CE294 @ =0x097471E2
	bl func_080028F8
	str r0, [r4, #0x00]
	ldr r0, _080CE298 @ =0x09849C78
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
_080CE25E:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x2C]
	adds r1, r1, r0
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r4, _080CE29C @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl func_080023E0
_080CE28C:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CE294: .4byte 0x097471E2
_080CE298: .4byte 0x09849C78
_080CE29C: .4byte 0xFFFFEFFC
.syntax divided

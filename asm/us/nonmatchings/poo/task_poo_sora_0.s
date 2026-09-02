.syntax unified
	.align 2, 0
	.global task_poo_sora_0
	.thumb
	.thumb_func
	.type task_poo_sora_0, %function
task_poo_sora_0: @ 080CABFC
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	adds r6, r0, #0x0
	ldr r5, _080CACE8 @ =0x0203C420
	ldr r0, _080CACEC @ =0x0203C414
	movs r1, #0x38
	adds r1, r1, r6
	mov r8, r1
	str r1, [r0, #0x00]
	ldr r0, _080CACF0 @ =0x0203C410
	movs r1, #0xB0
	adds r1, r1, r6
	mov r9, r1
	str r1, [r0, #0x00]
	ldr r0, _080CACF4 @ =0x02034DE8
	str r6, [r0, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x04
	movs r1, #0x00
	bl AllocObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080CACF8 @ =0x08F683A4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	movs r1, #0x00
	movs r4, #0x00
	movs r0, #0x10
	strh r0, [r5, #0x1A]
	adds r0, r6, #0x0
	adds r0, #0xAC
	strb r1, [r0, #0x00]
	subs r0, #0x14
	strh r4, [r0, #0x00]
	adds r0, #0x08
	strh r4, [r0, #0x00]
	adds r1, r6, #0x0
	adds r1, #0xA4
	movs r0, #0x0C
	str r0, [r1, #0x00]
	strh r4, [r5, #0x32]
	strh r4, [r5, #0x30]
	adds r0, r5, #0x0
	bl func_080D2D24
	movs r0, #0xAD
	strb r0, [r5, #0x14]
	str r4, [r5, #0x0C]
	str r4, [r5, #0x10]
	ldr r0, [r5, #0x00]
	ldr r1, [r5, #0x04]
	ldr r2, [r5, #0x08]
	adds r1, r1, r2
	bl func_080C9FA8
	adds r4, r6, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl AnimInit
	adds r0, r6, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080CAA50
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x20]
	adds r1, r6, #0x0
	adds r1, #0xA8
	ldr r0, _080CACFC @ =0x096FD2C4
	str r0, [r1, #0x00]
	adds r6, #0x24
	adds r0, r6, #0x0
	movs r1, #0x02
	bl TaskPoolInit
	ldr r4, _080CAD00 @ =0x02039BA0
	movs r0, #0xE8
	bl EwramAlloc
	str r0, [r4, #0x00]
	ldr r1, _080CAD04 @ =0x09EDAF90
	adds r0, r6, #0x0
	adds r2, r5, #0x0
	bl TaskCreate
	mov r0, r9
	movs r1, #0x01
	adds r2, r5, #0x0
	bl func_080CCB90
	mov r0, r8
	movs r1, #0x01
	movs r2, #0x12
	movs r3, #0x30
	bl func_080122AC
	ldr r1, [r5, #0x00]
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	mov r0, r8
	bl func_08012324
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CACE8: .4byte 0x0203C420
_080CACEC: .4byte 0x0203C414
_080CACF0: .4byte 0x0203C410
_080CACF4: .4byte 0x02034DE8
_080CACF8: .4byte 0x08F683A4
_080CACFC: .4byte 0x096FD2C4
_080CAD00: .4byte 0x02039BA0
_080CAD04: .4byte 0x09EDAF90
.syntax divided

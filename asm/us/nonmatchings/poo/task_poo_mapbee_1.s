.syntax unified
	.align 2, 0
	.global task_poo_mapbee_1
	.thumb
	.thumb_func
	.type task_poo_mapbee_1, %function
task_poo_mapbee_1: @ 080D23AC
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r0, #0x34
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D23BC
	movs r0, #0x00
	b _080D23FC
_080D23BC:
	ldrh r0, [r5, #0x36]
	cmp r0, #0x00
	beq _080D23C8
	cmp r0, #0x01
	beq _080D23E8
	b _080D23EE
_080D23C8:
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D23F2
	adds r0, r4, #0x0
	movs r1, #0x01
	movs r2, #0x01
	bl func_080059A4
	movs r0, #0x01
	strh r0, [r5, #0x36]
	b _080D23F2
_080D23E8:
	ldr r0, [r5, #0x2C]
	subs r0, #0xCC
	str r0, [r5, #0x2C]
_080D23EE:
	adds r4, r5, #0x0
	adds r4, #0x0C
_080D23F2:
	adds r0, r4, #0x0
	bl func_08005A64
	str r0, [r5, #0x08]
	movs r0, #0x01
_080D23FC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
